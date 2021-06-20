#pragma once

#include <SFML/Graphics.hpp>

class Canvas
{
public:
    sf::Uint8 *pixels;
    int w;
    int h;

    Canvas() {};
    Canvas(int w, int h);

    void set(int x, int y, sf::Color);
    void fill(sf::Color);
};