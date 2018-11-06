//
// Created by Ethan Nerney on 11/1/18.
//

#include "Entity.h"

Entity::Entity(position2D::Vector2D point): centerPoint(point) {
}

void Entity::translate(position2D::Vector2D v) {
    centerPoint.x += v.x;
    centerPoint.y += v.y;
    centerPoint.rotationAngle += v.rotationAngle;
}

void Entity::setPosition(position2D::Vector2D v) {
    centerPoint = v;
}

position2D::Vector2D Entity::getCenter() {
    return centerPoint;
}

void Entity::update() {}