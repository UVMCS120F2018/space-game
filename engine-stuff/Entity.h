//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_ENTITY_H
#define SPACE_STUFF_ENTITY_H

#include <stdlib.h>
#include <vector>

#include "structs.h"



class Entity {
protected:
    position2D::Vector2D centerPoint;

public:
    Entity(position2D::Vector2D point);

    void setPosition(position2D::Vector2D v);

    void translate(position2D::Vector2D v);

    position2D::Vector2D getCenter();

    virtual void update();

    virtual void draw() = 0;
};


#endif //SPACE_STUFF_ENTITY_H
