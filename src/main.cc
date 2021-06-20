#include <vector>
#include "core/window.hh"
#include "world/mesh.hh"
#include "world/world.hh"

int main()
{
    Mesh cube("res/objects/cube.obj");
    std::vector<Mesh> meshes = {cube};
    World world(meshes);

    Window window(800, 600);
    while (window.isopen())
    {
        window.draw(*(new World(world)));

        sf::Event event;
        while (window.poll(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}