#include "math/vector3.hh"
#include "world/camera.hh"

Camera::Camera(Vec3 pos, Vec3 forward, Vec3 up)
{
    this->pos = pos;
    this->forward = forward;
    this->up = up;
}

Camera::Camera(const Camera &camera)
{
    this->pos = Vec3(camera.pos);
    this->forward = Vec3(camera.forward);
    this->up = Vec3(camera.up);
}

Mat4 Camera::viewport()
{
    this->forward.normalize();
    this->up = (this->up - (this->forward * (this->up * this->forward))).normalize();
    Vec3 right = this->up ^ this->forward;

    return Mat4(new double[4][4]{
        {right.x, right.y, right.z, -this->pos * right},
        {this->up.x, this->up.y, this->up.z, -this->pos * this->up},
        {this->forward.x, this->forward.y, this->forward.z, -this->pos * this->forward},
        {0, 0, 0, 1}});
}

Camera &Camera::operator=(const Camera &camera)
{
    this->pos = Vec3(camera.pos);
    this->forward = Vec3(camera.forward);
    this->up = Vec3(camera.up);
    return *this;
}