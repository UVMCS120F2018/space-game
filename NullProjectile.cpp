//
// Created by Ethan Nerney on 11/9/18.
//

#include "NullProjectile.h"

NullProjectile::NullProjectile():Projectile(position2D::ZERO,position2D::ZERO) {}

void NullProjectile::update() {}

void NullProjectile::draw() {}