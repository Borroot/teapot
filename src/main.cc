#include <SFML/Window.hpp>
#include <vector>
#include "core/input.hh"
#include "core/window.hh"
#include "math/vector.hh"
#include "world/camera.hh"
#include "world/mesh.hh"
#include "world/world.hh"

int main()
{
    Window window(1200, 800, 2);

    Mesh axis("res/objects/axis.obj");
    std::vector<Mesh> meshes = {axis};
    Camera camera(Vec3(0, 0, -2), Vec3(0, 0, 1), Vec3(0, 1, 0));
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