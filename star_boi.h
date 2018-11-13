//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_STARBOI_H
#define SPACE_STUFF_STARBOI_H


#include "engine-stuff/circle.h"

class StarBoi: public Circle {
private:
    int rise;
    int run;
    int increment = 0;
    int max = 200;
    int startingRad;

    int height,width;
public:
    StarBoi(int rise, int run, int r, int boundsHeight, int boundsWidth, position2D::Vector2D point);

    void update() override;

};


#endif //SPACE_STUFF_STARBOI_H
