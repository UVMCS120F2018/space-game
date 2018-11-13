//
// Created by Ethan Nerney on 11/2/18.
//

#include "PhysicsCircle.h"

PhysicsCircle::PhysicsCircle(): Circle(10, position2D::Vector2D(250,250), colorGraphics::BLUE), p(this, 1, Circle(10, position2D::Vector2D(250,250), colorGraphics::BLUE)) {}

void PhysicsCircle::update() {
    p.update();
}