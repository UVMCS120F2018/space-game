//
// Created by Zach Bernstein on 11/13/18.
//

#include "asteroid.h"

Asteroid::Asteroid(int r, const position2D::Vector2D &center, const colorGraphics::RGBColor &color)
: Circle(r, center, color) {
}

std::string Asteroid::toString() {
    return "asteroid";
}

