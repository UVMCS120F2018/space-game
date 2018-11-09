//
// Created by Ethan Nerney on 11/7/18.
//

#ifndef SPACE_GAME_ROCKET_H
#define SPACE_GAME_ROCKET_H


#include "engine-stuff/Quadrangle.h"
#include "engine-stuff/ParticleSystem.h"
#include "engine-stuff/PhysicsAspect.h"

class Rocket: public Quadrangle {
private:
    int moveSpeed = 1;
    int turnSpeed = 1;

    ParticleSystem mainThruster;

    ParticleSystem rightThruster;
    ParticleSystem leftThruster;


public:
    Rocket(position2D::Vector2D center);

    void accelerateForward();
    void stopAccelerating();

    void turnRight();
    void stopRight();
    void turnLeft();
    void stopLeft();

    void draw() override;
    void update() override;
};


#endif //SPACE_GAME_ROCKET_H
