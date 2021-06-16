#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include "core/window.hh"

Window::Window(int w, int h)
{
    this->window.create(sf::VideoMode(w, h), "Teapot");
    this->window.setFramerateLimit(500);

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
            this->set(x, y, sf::Color::Black);
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

void Window::draw()
{
    this->texture.update(this->pixels);
    this->sprite.setTexture(this->texture);

    this->window.clear();

    this->window.draw(this->sprite);
    this->window.draw(this->fps());

    this->window.display();
}

void Window::set(int x, int y, sf::Color c)
{
    int index = this->w * y * 4 + x * 4;
    this->pixels[index + 0] = c.r;
    this->pixels[index + 1] = c.g;
    this->pixels[index + 2] = c.b;
    this->pixels[index + 3] = c.a;
}