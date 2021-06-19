#pragma once

#include <SFML/Graphics.hpp>
#include "world/world.hh"

void render(World &, sf::Uint8 *, int w, int h);
void background(sf::Uint8 *, int w, int h, sf::Color);