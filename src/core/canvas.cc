#include "core/canvas.hh"

Canvas::Canvas(int w, int h)
{
    this->pixels = new sf::Uint8[w * h * 4];
    this->w = w;
    this->h = h;
}

void Canvas::set(int x, int y, sf::Color c)
{
    int index = this->w * y * 4 + x * 4;
    this->pixels[index + 0] = c.r;
    this->pixels[index + 1] = c.g;
    this->pixels[index + 2] = c.b;
    this->pixels[index + 3] = c.a;
}