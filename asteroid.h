//
// Created by Zach Bernstein on 11/13/18.
//

#ifndef SPACE_GAME_ASTEROID_H
#define SPACE_GAME_ASTEROID_H


#include "engine-stuff/circle.h"

class Asteroid : public Circle {
private:
    int rate = 2;
public:
    position2D::Vector2D velocity;

    Asteroid(int r, const position2D::Vector2D &center, const colorGraphics::RGBColor &color, position2D::Vector2D v);
    // they dont do anything lol

    std::string toString() override;

    void update() override;
};



#endif //SPACE_GAME_ASTEROID_H
