#include <SFML/Window.hpp>
#include <vector>
#include "core/update.hh"
#include "core/window.hh"
#include "math/vector3.hh"
#include "world/camera.hh"
#include "world/mesh.hh"
#include "world/world.hh"

int main()
{
    Window window(1200, 800, 2);

    Mesh axis("res/objects/axis.obj");
    Mesh teapot("res/objects/teapot.obj");
    Mat4::translate(1, 1, 2) * teapot;
    std::vector<Mesh> meshes = {axis, teapot};
    Camera camera(Vec3(0, 0, -2));
    World world(meshes, camera);

    sf::Clock clock;
    sf::Time lasttick = clock.getElapsedTime();

    while (window.isopen())
    {
        sf::Time thistick = clock.getElapsedTime();
        double dt = thistick.asSeconds() - lasttick.asSeconds();
        lasttick = thistick;

        update(window, world, dt);
        window.draw(world, dt);
    }
    return EXIT_SUCCESS;
}