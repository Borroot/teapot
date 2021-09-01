#include "ui/debug.hh"

static std::string pos(const World &world)
{
    std::string x = std::to_string(world.camera.pos.x);
    std::string y = std::to_string(world.camera.pos.y);
    std::string z = std::to_string(world.camera.pos.z);
    return "xyz: " + x + " " + y + " " + z + "\n";
}

static std::string fps(double dt)
{
    return "fps: " + std::to_string((int)(1 / dt)) + "\n";
}

std::string debug(const World &world, double dt)
{
    return fps(dt) + pos(world);
}