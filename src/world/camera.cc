#include <math.h>
#include "math/vector3.hh"
#include "world/camera.hh"

Camera::Camera(Vec3 pos)
{
    this->pos = pos;
}

void Camera::update_pitch(double rad)
{
    pitch += rad;
    if (pitch >  M_PI_2) pitch =  M_PI_2;
    if (pitch < -M_PI_2) pitch = -M_PI_2;
}

void Camera::update_yaw(double rad)
{
    yaw += rad;
    if (yaw > 2 * M_PI) yaw -= 2 * M_PI;
    if (yaw < 0) yaw += 2 * M_PI;
}

double Camera::get_pitch()
{
    return this->pitch;
}

double Camera::get_yaw()
{
    return this->yaw;
}

Vec3 Camera::forward()
{
    Mat4 pitch = Mat4::rotx(this->pitch);
    Mat4 yaw = Mat4::roty(this->yaw);
    return (yaw * pitch * Vec3(0, 0, 1)).normalize();
}

Mat4 Camera::view_matrix()
{
    Vec3 forward = this->forward();
    Vec3 up = (Vec3(0, 1, 0) - (forward * (Vec3(0, 1, 0) * forward))).normalize();
    Vec3 right = up ^ forward;

    return Mat4(new double[4][4]{
        {right.x, right.y, right.z, -pos * right},
        {up.x, up.y, up.z, -pos * up},
        {forward.x, forward.y, forward.z, -pos * forward},
        {0, 0, 0, 1}});
}