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
    this->up.normalize();  // TODO forward can add pitch to up
    Vec3 right = this->up ^ this->forward;

    return Mat4(new double[4][4]{
        {right.x, this->up.x, this->forward.x, 0},
        {right.y, this->up.y, this->forward.y, 0},
        {right.z, this->up.z, this->forward.z, 0},
        {-(this->pos * right), -(this->pos * this->up), -(this->pos * this->forward), 1}});
}

Camera &Camera::operator=(const Camera &camera)
{
    this->pos = Vec3(camera.pos);
    this->forward = Vec3(camera.forward);
    this->up = Vec3(camera.up);
    return *this;
}