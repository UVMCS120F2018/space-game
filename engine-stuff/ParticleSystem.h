//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_PARTICLESYSTEM_H
#define SPACE_STUFF_PARTICLESYSTEM_H


#include <vector>
#include "Entity.h"
#include "Circle.h"
#include "Particle.h"

class ParticleSystem: public Entity {
private:
    int particles;
    int particleSize;
    int rate;
    int increment;
    int length;
    int arcAngle;

    bool canDraw = true;

    Circle generator;

    std::vector<Particle> particleEntities;

    colorGraphics::RGBColor partColor;
public:
    ParticleSystem(int particleNum, int generationRate, int length, int arcAngle, int arcHeight, int partSize,
                   colorGraphics::RGBColor particleColor, position2D::Vector2D centerPoint);

    void draw() override;
    void update() override;

    void start();
    void stop();

};


#endif //SPACE_STUFF_PARTICLESYSTEM_H
