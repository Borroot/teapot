#pragma once

#include <SFML/Graphics.hpp>
#include "render/color.hh"

class window
{
private:
    sf::RenderWindow win;
    int w;  // width  of the window
    int h;  // height of the window

    sf::Uint8 *pixels;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;

    sf::Clock clock;
    sf::Time prevdraw;

    sf::Text fps();

public:
    window() {};
    window(int w, int h);

    bool isopen();
    void close();

    bool poll(sf::Event &);

    void draw();
    void set(int x, int y, color c);
};