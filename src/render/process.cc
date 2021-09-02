#include "render/process.hh"
#include "world/mesh.hh"

void populate(const World &world, std::list<Triangle> &triangles)
{
    for (Mesh mesh : world.meshes)
        for (Triangle triangle : mesh.triangles)
                triangles.push_back(triangle);
}

void backface_culling(std::list<Triangle> &triangles, Vec3 ref)
{
    triangles.remove_if([&](Triangle &triangle) {
        return (triangle.v0 - ref) * triangle.normal() >= 0;
    });
}

void shade(std::list<Triangle> &triangles)
{
    Vec3 light = Vec3(0.5, 1, -1).normalize();
    std::for_each(triangles.begin(), triangles.end(), [&](Triangle &triangle) {
        double shade = light * triangle.normal();
        triangle.color = sf::Color(shade * 255, shade * 255, shade * 255, 255);
    });
}

void painters_algorithm(std::list<Triangle> &triangles, const Vec3 &ref)
{
    triangles.sort([&](Triangle &t1, Triangle &t2) {
        double average1 = (Vec3::dist_fast(t1.v0, ref) + Vec3::dist_fast(t1.v1, ref) + Vec3::dist_fast(t1.v2, ref)) / 3;
        double average2 = (Vec3::dist_fast(t2.v0, ref) + Vec3::dist_fast(t2.v1, ref) + Vec3::dist_fast(t2.v2, ref)) / 3;
        return average1 > average2;
    });
}

void clip_farnear(std::list<Triangle> &triangles, double far, double near)
{
    triangles.remove_if([&](Triangle &triangle) {
        return
            (triangle.v0.z < near && triangle.v1.z < near && triangle.v2.z < near) ||
            (triangle.v0.z > far  && triangle.v1.z > far  && triangle.v2.z > far);
    });
}

void clip_properly(std::list<Triangle> &triangles)
{
    // TODO
    return;
}

void apply_matrix(std::list<Triangle> &triangles, Mat4 matrix)
{
    std::for_each(triangles.begin(), triangles.end(), [&](Triangle &triangle) {
        matrix * triangle;
    });
}

void draw(std::list<Triangle> &triangles, Canvas &canvas)
{
    std::for_each(triangles.begin(), triangles.end(), [&](Triangle &triangle) {
        triangle.draw(canvas, true, false);
    });
}