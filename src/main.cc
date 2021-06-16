#include "core/window.hh"

int main()
{
    window win;
    while (win.isopen())
    {
        win.draw();

        sf::Event event;
        while (win.poll(event))
            if (event.type == sf::Event::Closed)
                win.close();
    }

    return EXIT_SUCCESS;
}