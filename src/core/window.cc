#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include <cstring>
#include "core/canvas.hh"
#include "core/window.hh"
#include "render/render.hh"

Window::Window(int w, int h, double scale)
{
    this->w = w;
    this->h = h;

    this->window.create(sf::VideoMode(w, h), "Teapot");
    this->window.setFramerateLimit(500);

    double width = w / scale;
    double height = h / scale;

    this->canvas = Canvas(width, height);
    this->canvas.fill(sf::Color::Black);

    this->render = Render(width, height);
    this->sprite.setScale(scale, scale);

    if (!this->texture.create(width, height))
        throw std::runtime_error("Could not create texture.");

    if (!this->font.loadFromFile("res/fonts/SansMono-Regular.ttf"))
        throw std::runtime_error("Could not load font.");

    sf::Mouse::setPosition(sf::Vector2i(w / 2, h / 2), this->window);
    this->window.setMouseCursorGrabbed(true);
    this->window.setMouseCursorVisible(false);

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

sf::Text Window::fps(double dt)
{
    sf::Text text("fps: " + std::to_string((int)(1 / dt)), this->font, 15);
    text.setFillColor(sf::Color::White);
    return text;
}

void Window::draw(const World &world, double dt)
{
    this->canvas.fill(sf::Color::Black);
    this->render.render(world, canvas);

    this->texture.update(this->canvas.pixels);
    this->sprite.setTexture(this->texture);

    this->window.clear();

    this->window.draw(this->sprite);
    this->window.draw(this->fps(dt));

    this->window.display();
}