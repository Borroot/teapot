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

    Window window(1200, 900, 3);

    sf::Clock clock;
    sf::Time prevtime = clock.getElapsedTime();
    double rad = 0;

    while (window.isopen())
    {
        sf::Time currtime = clock.getElapsedTime();
        rad += 1 * (currtime.asSeconds() - prevtime.asSeconds());
        prevtime = currtime;

        World world_clone(world);

        // Mat4 rot = Mat4::rotx(rad);
        // rot * world_clone.meshes[0];

        window.draw(world_clone);

        sf::Event event;
        while (window.poll(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}