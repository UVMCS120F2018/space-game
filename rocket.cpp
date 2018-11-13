//
// Created by Ethan Nerney on 11/7/18.
//

#include "rocket.h"
#include "projectile.h"
#include "null_projectile.h"

Rocket::Rocket(position2D::Vector2D center): Quadrangle(50,20, center, colorGraphics::GRAY),
                                             mainThruster(50, 1, 8, 20, 28, 3, colorGraphics::FIRE,
                                                          position2D::Vector2D(center.x, center.y, 180)),
                                            rightThruster(25, 1, 3, 5, 15, 2, colorGraphics::FIRE,position2D::Vector2D(center.x, center.y, 135)),
leftThruster(25, 1, 3, 5, 15, 2, colorGraphics::FIRE,position2D::Vector2D(center.x, center.y, -135)){
    mainThruster.stop();
    rightThruster.stop();
    leftThruster.stop();

}

void Rocket::accelerateForward() {
    mainThruster.start();
}

void Rocket::stopAccelerating() {
    mainThruster.stop();
}

void Rocket::turnRight() {
    rightThruster.start();
}

void Rocket::stopRight() {
    rightThruster.stop();
}

void Rocket::turnLeft() {
    leftThruster.start();
}

void Rocket::stopLeft() {
    leftThruster.stop();
}

void Rocket::update() {
    mainThruster.setPosition(position2D::Vector2D(centerPoint.x, centerPoint.y, centerPoint.rotationAngle + 180));
    rightThruster.setPosition(position2D::Vector2D(centerPoint.x, centerPoint.y, centerPoint.rotationAngle + 135));
    leftThruster.setPosition(position2D::Vector2D(centerPoint.x, centerPoint.y, centerPoint.rotationAngle - 135));
    mainThruster.update();
    rightThruster.update();
    leftThruster.update();
}

void Rocket::draw() {
    Quadrangle::draw();
    mainThruster.draw();
    rightThruster.draw();
    leftThruster.draw();
}

Projectile* Rocket::shoot() {

    if (ammo > 0) {
        double theta = getCenter().rotationAngle * M_PI / 180;
        double x = cosf(theta);
        double y = sinf(theta);
        position2D::Vector2D start(x + getCenter().x, y + getCenter().y);
        position2D::Vector2D force(x, y);


        Circle c(5, start, colorGraphics::RED);
        Projectile *p = new Projectile(start, force * 10);

        ammo--;

        return p;
    }

    NullProjectile *n = new NullProjectile;
    return n;

}