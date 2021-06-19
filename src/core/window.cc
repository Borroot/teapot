#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include <cstring>
#include "core/window.hh"
#include "render/render.hh"

Window::Window(int w, int h)
{
    this->window.create(sf::VideoMode(w, h), "Teapot");
    this->window.setFramerateLimit(500);

    this->w = w;
    this->h = h;

    // times 4 since every pixel is 4 bytes RGBA
    this->pixels = new sf::Uint8[this->w * this->h * 4];
    background(pixels, this->w, this->h, sf::Color::Black);

    if (!this->texture.create(this->w, this->h))
        throw std::runtime_error("Could not create texture.");

    if (!this->font.loadFromFile("res/fonts/SansMono-Regular.ttf"))
        throw std::runtime_error("Could not load font.");
}

bool Window::isopen()
{
    return this->window.isOpen();
}

void Window::close()
{
    delete this->pixels;
    this->window.close();
}

bool Window::poll(sf::Event &event)
{
    return this->window.pollEvent(event);
}

sf::Text Window::fps()
{
    sf::Time currtime = clock.getElapsedTime();
    int fps = 1.f / (currtime.asSeconds() - this->prevdraw.asSeconds());
    this->prevdraw = currtime;

    sf::Text text("fps: " + std::to_string(fps), this->font, 15);
    text.setFillColor(sf::Color::White);
    return text;
}

void Window::draw(World &world)
{
    render(world, this->pixels, this->w, this->h);

    this->texture.update(this->pixels);
    this->sprite.setTexture(this->texture);

    this->window.clear();

    this->window.draw(this->sprite);
    this->window.draw(this->fps());

    this->window.display();
}