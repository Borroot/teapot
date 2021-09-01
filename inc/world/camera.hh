#pragma once

#include "math/matrix.hh"
#include "math/vector3.hh"

class Camera
{
private:
    double pitch = 0;  // in radians
    double yaw = 0;    // in radians

public:
    Vec3 pos;  // location in world space

    Camera() = default;
    Camera(Vec3 pos);

    void update_pitch(double rad);
    void update_yaw(double rad);

    Vec3 forward();
    Mat4 view_matrix();
};