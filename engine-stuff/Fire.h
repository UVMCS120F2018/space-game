//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_FIRE_H
#define SPACE_STUFF_FIRE_H


#include "Entity.h"
#include "ParticleSystem.h"

class Fire: public Entity {
private:
    ParticleSystem smoke;
    ParticleSystem top;
    ParticleSystem mid;
    ParticleSystem bot;
public:
    Fire(int length, colorGraphics::RGBColor smokeColor, colorGraphics::RGBColor topColor,
         colorGraphics::RGBColor midColor, colorGraphics::RGBColor botColor, position2D::Vector2D center);

    void update() override;
    void draw() override;
};


#endif //SPACE_STUFF_FIRE_H
