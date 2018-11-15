//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_STARSYSTEM_H
#define SPACE_STUFF_STARSYSTEM_H


#include <vector>
#include "engine-stuff/entity.h"
#include "star_boi.h"

class HyperSpace: public Entity {
private:
    int particles;
    int width;
    int height;
    int rate;
    int increment;

    Circle c;

    std::vector<StarBoi> starBois;

public:
    HyperSpace(int particleNums, int particleRate, int boundsWidth, int boundsHeight, position2D::Vector2D point);

    void draw() override;
    void update() override;

};


#endif //SPACE_STUFF_STARSYSTEM_H
