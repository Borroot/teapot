#include <list>
#include <iostream>
#include "math/intersect.hh"
#include "render/clipping.hh"

static void clip_plane(Vec3 plane_point, Vec3 plane_normal, Triangle &triangle, std::list<Triangle> &triangles_new)
{
    plane_normal.normalize();
    std::list<Vec3> inside, outside;

    auto distance = [&](Vec3 point) -> double {  // signed shortest distance from point to plane
        return plane_normal * (point - plane_point);
    };

    double d0 = distance(triangle.v0);
    double d1 = distance(triangle.v1);
    double d2 = distance(triangle.v2);

    if (d0 >= 0) inside.push_back(triangle.v0);
    else outside.push_back(triangle.v0);
    if (d1 >= 0) inside.push_back(triangle.v1);
    else outside.push_back(triangle.v1);
    if (d2 >= 0) inside.push_back(triangle.v2);
    else outside.push_back(triangle.v2);

    if (inside.size() == 0)  // all outside so no valid triangle
        return;

    if (inside.size() == 3)  // all inside so valid triangle
    {
        triangles_new.push_back(triangle);
        return;
    }

    if (inside.size() == 1)
    {
        Triangle t;

        t.color = triangle.color;
        t.v0 = inside.front();

        Vec3 a = intersect_plane(plane_point, plane_normal, inside.front(), outside.front());
        Vec3 b = intersect_plane(plane_point, plane_normal, inside.front(), outside.back());

        // make sure the triangle rotations are clockwise
        if (d1 < 0)
        {  // if v1 is outside
            t.v1 = a;
            t.v2 = b;
        }
        else
        {  // if v0 or v2 is outside
            t.v1 = b;
            t.v2 = a;
        }

        triangles_new.push_back(t);
        return;
    }

    if (inside.size() == 2)
    {
        Triangle t1, t2;

        t1.color = triangle.color;
        t2.color = triangle.color;

        t1.v0 = inside.front();
        t2.v0 = inside.back();

        Vec3 a = intersect_plane(plane_point, plane_normal, inside.front(), outside.front());
        Vec3 b = intersect_plane(plane_point, plane_normal, inside.back(), outside.front());

        // make sure the triangle rotations are clockwise
        if (d1 < 0)
        {  // if v1 is outside
            t1.v1 = a;
            t1.v2 = inside.back();
            t2.v1 = a;
            t2.v2 = b;
        }
        else
        {  // if v0 or v2 is outside
            t1.v1 = inside.back();
            t1.v2 = a;
            t2.v1 = b;
            t2.v2 = a;
        }

        triangles_new.push_back(t1);
        triangles_new.push_back(t2);
        return;
    }
}

void clip_frustum(std::list<Triangle> &triangles, int w, int h)
{
    double pw = 1.0 / w;  // one pixel on the canvas width
    double ph = 1.0 / h;  // one pixel on the canvas height

    std::list<Triangle> triangles_final;
    for (Triangle &triangle : triangles)
    {
        std::list<Triangle> queue;
        queue.push_back(triangle);

        for (int plane = 0; plane < 4; plane++)
        {
            int size = queue.size();
            while (size > 0)
            {
                Triangle test = queue.front();
                queue.pop_front();
                size--;

                std::list<Triangle> triangles_new;

                switch (plane)
                {
                case 0: clip_plane(Vec3( 1-pw,     0,   0), Vec3(-1,  0, 0), test, triangles_new); break;  // right
                case 1: clip_plane(Vec3(-1+pw,     0,   0), Vec3( 1,  0, 0), test, triangles_new); break;  // left
                case 2: clip_plane(Vec3(    0,  1-ph,   0), Vec3( 0, -1, 0), test, triangles_new); break;  // top
                case 3: clip_plane(Vec3(    0, -1+ph,   0), Vec3( 0,  1, 0), test, triangles_new); break;  // bottom
                }

                for (Triangle &t : triangles_new)
                    queue.push_back(t);
            }
        }
        for (Triangle &t : queue)
            triangles_final.push_back(t);
    }
    triangles.swap(triangles_final);
}

void clip_farnear(std::list<Triangle> &triangles, double far, double near)
{
    triangles.remove_if([&](Triangle &triangle) {
        triangle.normalize_w();
        return
            (triangle.v0.z < near && triangle.v1.z < near && triangle.v2.z < near) ||
            (triangle.v0.z > far  && triangle.v1.z > far  && triangle.v2.z > far);
    });

    std::list<Triangle> triangles_final;
    for (Triangle &triangle : triangles)
    {
        std::list<Triangle> triangles_new;
        clip_plane(Vec3(0, 0, near), Vec3(0, 0, 1), triangle, triangles_new);

        for (Triangle &t : triangles_new)
            triangles_final.push_back(t);
    }
    triangles.swap(triangles_final);
}