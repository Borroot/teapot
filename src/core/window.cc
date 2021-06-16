#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "core/window.hh"

window::window()
{
    this->win.create(sf::VideoMode(500, 500), "Teapot");
    this->win.setFramerateLimit(500);

    this->w = this->win.getSize().x;
    this->h = this->win.getSize().y;

    // times 4 since every pixel is 4 bytes RGBA
    this->pixels = new sf::Uint8[this->w * this->h * 4];

    if (!texture.create(this->w, this->h))
        throw std::runtime_error("Could not create texture.");

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

void window::fps()
{
    sf::Time currtime = clock.getElapsedTime();
    float fps = 1.f / (currtime.asSeconds() - this->prevdraw.asSeconds());
    this->prevdraw = currtime;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(0) << fps;
    this->win.setTitle("fps: " + stream.str());
}

void window::draw()
{
    this->texture.update(this->pixels);
    this->sprite.setTexture(this->texture);

    this->fps();

    this->win.clear();
    this->win.draw(this->sprite);
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