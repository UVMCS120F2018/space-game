//
// Created by Ethan Nerney on 11/7/18.
//

#ifndef SPACE_GAME_ROCKET_H
#define SPACE_GAME_ROCKET_H


#include "engine-stuff/quadrangle.h"
#include "engine-stuff/particle_system.h"
#include "engine-stuff/physics_aspect.h"
#include "projectile.h"

class Rocket: public Quadrangle {
private:
    int moveSpeed = 1;
    int turnSpeed = 1;

    int ammo = 10;

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
    std::string toString() override;

    Projectile* shoot();
};


#endif //SPACE_GAME_ROCKET_H
