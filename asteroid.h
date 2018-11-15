//
// Created by Zach Bernstein on 11/13/18.
//

#ifndef SPACE_GAME_ASTEROID_H
#define SPACE_GAME_ASTEROID_H


#include "engine-stuff/circle.h"

class Asteroid : public Circle {
public:
    Asteroid(int r, const position2D::Vector2D &center, const colorGraphics::RGBColor &color);
    // they dont do anything lol

    std::string toString() override;
};


#endif //SPACE_GAME_ASTEROID_H
