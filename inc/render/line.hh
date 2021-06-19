#pragma once

#include <SFML/Graphics.hpp>
#include "core/canvas.hh"

void draw_line(Canvas &, int x1, int y1, int x2, int y2, sf::Color);
void draw_line(Canvas &, int x1, int y1, int x2, int y2, sf::Color, int thickness);