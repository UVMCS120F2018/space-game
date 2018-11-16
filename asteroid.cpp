//
// Created by Zach Bernstein on 11/13/18.
//

#include "asteroid.h"

Asteroid::Asteroid(int r, const position2D::Vector2D &center, const colorGraphics::RGBColor &color, position2D::Vector2D v)
: Circle(r, center, color), velocity(v) {
}

std::string Asteroid::toString() {
    return "asteroid";
}

void Asteroid::update() {
    if (rate > 0) {
        rate--;
    } else {
        translate(velocity);
        rate = 2;
    }
    if (getCenter().x < 0 or getCenter().x > 1200) {
        velocity.x = -velocity.x;
    }

    if (getCenter().y < 0 or getCenter().y > 600) {
        velocity.y = -velocity.y;
    }
}

