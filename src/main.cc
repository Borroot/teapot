#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "");
    // window.setFramerateLimit(60);

    sf::Vector2u size = window.getSize();
    sf::Uint8 *pixels = new sf::Uint8[size.x * size.y * 4];

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.create(size.x, size.y))
    {
        std::cerr << "Could not create texture." << std::endl;
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < size.x * size.y * 4; i += 4)
    {
        pixels[i] = 0xAA;     // r
        pixels[i + 1] = 0x44; // g
        pixels[i + 2] = 0xAA; // b
        pixels[i + 3] = 0xFF; // a: 0xFF is not transparent
    }
    texture.update(pixels);
    sprite.setTexture(texture); // update sprite after texture was updated

    sf::Clock clock;
    sf::Time prevtime = clock.getElapsedTime();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time currtime = clock.getElapsedTime();
        float fps = 1.f / (currtime.asSeconds() - prevtime.asSeconds());
        prevtime = currtime;

        std::stringstream stream;
        stream << std::fixed << std::setprecision(0) << fps;
        window.setTitle("fps: " + stream.str());

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}