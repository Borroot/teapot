#pragma once

#include "math/matrix.hh"
#include "math/vector3.hh"

class Camera
{
public:
    Vec3 pos;     // location of the camera in world space
    Vec3 forward; // direction along the camera points
    Vec3 up;      // the up vector

    Camera() = default;
    Camera(Vec3 pos, Vec3 forward, Vec3 up);
    Camera(const Camera &);

    Mat4 viewport();  // world space to camera space matrix

    Camera &operator=(const Camera &);
};