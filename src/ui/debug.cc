#include "ui/debug.hh"

static std::string fps(double dt)
{
    return "fps: " + std::to_string((int)(1 / dt)) + "\n";
}

static std::string pos(Camera &camera)
{
    std::string x = std::to_string(camera.pos.x);
    std::string y = std::to_string(camera.pos.y);
    std::string z = std::to_string(camera.pos.z);
    return "xyz: " + x + " " + y + " " + z + "\n";
}

static std::string pitchyaw(Camera &camera)
{
    std::string pitch = std::to_string(camera.get_pitch());
    std::string yaw = std::to_string(camera.get_yaw());
    return "pitch yaw: " + pitch + " " + yaw + "\n";
}

std::string debug(const World &world, double dt)
{
    Camera camera = world.camera;
    return fps(dt) + pos(camera) + pitchyaw(camera);
}