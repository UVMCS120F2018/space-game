//
// Created by Ethan Nerney on 11/9/18.
//

#ifndef SPACE_GAME_PROJECTILE_H
#define SPACE_GAME_PROJECTILE_H


#include "engine-stuff/Circle.h"

class Projectile: public Circle {
private:
    position2D::Vector2D v;
public:
    Projectile(position2D::Vector2D start, position2D::Vector2D velocity);

    void update() override;

};


#endif //SPACE_GAME_PROJECTILE_H
