#include <iostream>
#include <vector>
#include "core/window.hh"
#include "math/vector.hh"
#include "world/camera.hh"
#include "world/mesh.hh"
#include "world/world.hh"

int main()
{
    Mesh axis("res/objects/axis.obj");
    std::vector<Mesh> meshes = {axis};
    Camera camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0));
    World world(meshes, camera);

    Window window(1200, 800, 2);

    sf::Clock clock;
    sf::Time lasttick = clock.getElapsedTime();

    double rad = 0;

    while (window.isopen())
    {
        sf::Time thistick = clock.getElapsedTime();
        double dt = thistick.asSeconds() - lasttick.asSeconds();
        lasttick = thistick;

        World world_clone(world);

        rad += 1 * dt;
        Mat4 rot = Mat4::rotz(rad);
        rot * world_clone.meshes[0];

        window.draw(world_clone, dt);

        sf::Event event;
        while (window.poll(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}