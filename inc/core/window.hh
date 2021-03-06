#pragma once

#include <SFML/Graphics.hpp>
#include "core/canvas.hh"
#include "render/render.hh"
#include "world/world.hh"

class Window
{
private:
    Canvas canvas;
    Render render;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    sf::Text text(std::string);

public:
    sf::RenderWindow window;
    bool mouse; // true if grabbed and invisible

    int w;
    int h;

    Window() = default;
    Window(int w, int h, double scale);

    bool isopen();
    void close();

    bool poll(sf::Event &);

    void draw(const World &, double dt);
    void set_mouse(bool);
};