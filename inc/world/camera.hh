#pragma once

#include "math/matrix.hh"
#include "math/vector3.hh"

class Camera
{
private:
    double pitch = 0;  // current pitch in radians
    double yaw = 0;    // current yaw in radians

    Vec3 up;  // the up vector

public:
    Vec3 pos;     // location of the camera in world space
    Vec3 forward; // direction along the camera points

    Camera() = default;
    Camera(Vec3 pos, Vec3 forward, Vec3 up);

    // void addpitch(double rad);
    // void addyaw(double rad);

    Mat4 viewport();  // world space to camera space matrix
};