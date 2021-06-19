#pragma once

#include <SFML/Graphics.hpp>
#include "core/canvas.hh"
#include "world/world.hh"

class Window
{
private:
    sf::RenderWindow window;
    Canvas canvas;

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

    void draw(World &);
    void set(int x, int y, sf::Color c);
};