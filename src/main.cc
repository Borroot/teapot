#include <iostream>
#include <vector>
#include "core/window.hh"
#include "world/mesh.hh"
#include "world/world.hh"

int main()
{
    // Mesh cube("res/objects/cube.obj");
    Mesh teapot("res/objects/teapot.obj");
    std::vector<Mesh> meshes = {teapot};
    World world(meshes);

    Window window(1200, 900, 3);

    sf::Clock clock;
    sf::Time prevtime = clock.getElapsedTime();
    double rad = 0;

    while (window.isopen())
    {
        sf::Time currtime = clock.getElapsedTime();
        rad += 1 * (currtime.asSeconds() - prevtime.asSeconds());
        prevtime = currtime;

        Mat4 rotx = Mat4::rotx(rad);
        Mat4 rotz = Mat4::rotz(rad + 0.5);

        World world_clone = World(world);
        rotx * rotz * world_clone.meshes[0];

        window.draw(world_clone);

        sf::Event event;
        while (window.poll(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}