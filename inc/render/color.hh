#pragma once

typedef struct
{
    sf::Uint8 r;
    sf::Uint8 g;
    sf::Uint8 b;
    sf::Uint8 a;
} color;

constexpr color BLACK = {0x00, 0x00, 0x00, 0xFF};
constexpr color WHITE = {0xFF, 0xFF, 0xFF, 0xFF};
