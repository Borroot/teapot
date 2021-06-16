#include "render/pixel.hh"

void set(sf::Uint8 *pixels, int w, int x, int y, sf::Color c)
{
    int index = w * y * 4 + x * 4;
    pixels[index + 0] = c.r;
    pixels[index + 1] = c.g;
    pixels[index + 2] = c.b;
    pixels[index + 3] = c.a;
}
