#pragma once

#include <SFML/Graphics.hpp>
#include "world/world.hh"

void render(World &, Canvas &);
void background(Canvas &, sf::Color);