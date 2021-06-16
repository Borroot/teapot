#pragma once

#include <SFML/Graphics.hpp>
#include "world/world.hh"

class Window
{
private:
    sf::RenderWindow window;
    int w;  // width  of the <Window>
    int h;  // height of the <Window>

    sf::Uint8 *pixels;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;

    sf::Clock clock;
    sf::Time prevdraw;

    sf::Text fps();

public:
    Window(int w, int h);

    bool isopen();
    void close();

    bool poll(sf::Event &);

    void draw(const World &);
    void set(int x, int y, sf::Color c);
};