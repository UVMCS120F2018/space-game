//
// Created by Ethan Nerney on 11/2/18.
//

#include <math.h>
#include "Particle.h"

Particle::Particle(int size, position2D::Vector2D center, position2D::Vector2D velo, colorGraphics::RGBColor color, int life): Circle(size, center, color), velocity(velo), startPoint(center) {
    lifeSpan = life;
    theta = velo.rotationAngle * M_PI /180;
}

void Particle::update() {
    if (increment < lifeSpan) {
        increment++;

        xMotion += cosf(theta);
        yMotion += sinf(theta);

        translate(position2D::Vector2D(xMotion, yMotion));

        xMotion = fmod(xMotion, 1);
        yMotion = fmod(yMotion, 1);


    } else {
        increment = 0;
        setPosition(startPoint);
    }
}