//
// Created by Ethan Nerney on 11/9/18.
//

#include "projectile.h"

Projectile::Projectile(position2D::Vector2D start, position2D::Vector2D velocity): Circle(5, start, colorGraphics::RED), v(velocity) {}

void Projectile::update() {
    translate(v);
}

std::string Projectile::toString() {
    return "projectile";
}