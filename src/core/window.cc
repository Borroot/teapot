#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include <cstring>
#include "core/canvas.hh"
#include "core/window.hh"
#include "render/render.hh"

Window::Window(int w, int h, double scale)
{
    this->window.create(sf::VideoMode(w, h), "Teapot");
    this->window.setFramerateLimit(500);

    this->canvas = Canvas(w / scale, h / scale);
    this->canvas.fill(sf::Color::Black);

    this->sprite.setScale(scale, scale);

    if (!this->texture.create(w / scale, h / scale))
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
    render(world, canvas);

    this->texture.update(this->canvas.pixels);
    this->sprite.setTexture(this->texture);

    this->window.clear();

    this->window.draw(this->sprite);
    this->window.draw(this->fps());

    this->window.display();
}