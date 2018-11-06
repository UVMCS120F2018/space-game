//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_PHYSICSCIRCLE_H
#define SPACE_STUFF_PHYSICSCIRCLE_H


#include "Circle.h"
#include "PhysicsAspect.h"

class PhysicsCircle: public Circle {
public:
    PhysicsAspect p;

    PhysicsCircle();
    void update() override;
};


#endif //SPACE_STUFF_PHYSICSCIRCLE_H
