#include "core/window.hh"

int main()
{
    Window window(1200, 800);
    while (window.isopen())
    {
        window.draw();

        sf::Event event;
        while (window.poll(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}