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
    Window window(1000, 800, 2);

    Mesh obj("res/objects/cube.obj");
    std::vector<Mesh> meshes = {obj};
    Camera camera(Vec3(0, 0, -3));
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