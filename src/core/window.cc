#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include "core/window.hh"

window::window(int w, int h)
{
    this->win.create(sf::VideoMode(w, h), "Teapot");
    this->win.setFramerateLimit(500);

    this->w = w;
    this->h = h;

    // times 4 since every pixel is 4 bytes RGBA
    this->pixels = new sf::Uint8[this->w * this->h * 4];

    if (!this->texture.create(this->w, this->h))
        throw std::runtime_error("Could not create texture.");

    if (!this->font.loadFromFile("res/fonts/SansMono-Regular.ttf"))
        throw std::runtime_error("Could not load font.");

    for (int y = 0; y < this->h; y++)
        for (int x = 0; x < this->w; x++)
            this->set(x, y, WHITE);
}

bool window::isopen()
{
    return this->win.isOpen();
}

void window::close()
{
    delete this->pixels;
    this->win.close();
}

bool window::poll(sf::Event &event)
{
    return this->win.pollEvent(event);
}

sf::Text window::fps()
{
    sf::Time currtime = clock.getElapsedTime();
    int fps = 1.f / (currtime.asSeconds() - this->prevdraw.asSeconds());
    this->prevdraw = currtime;

    sf::Text text("fps: " + std::to_string(fps), this->font, 15);
    text.setFillColor(sf::Color(0x000000FF));
    return text;
}

void window::draw()
{
    this->texture.update(this->pixels);
    this->sprite.setTexture(this->texture);

    this->win.clear();

    this->win.draw(this->sprite);
    this->win.draw(this->fps());

    this->win.display();
}

void window::set(int x, int y, color c)
{
    int index = this->w * y * 4 + x * 4;
    this->pixels[index + 0] = c.r;
    this->pixels[index + 1] = c.g;
    this->pixels[index + 2] = c.b;
    this->pixels[index + 3] = c.a;
}