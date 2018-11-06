//
// Created by Ethan Nerney on 11/2/18.
//

#include <math.h>
#include <iostream>
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(int particleNum, int generationRate,
                               int length, int arcAngle, int arcHeight, int partSize,
                               colorGraphics::RGBColor particleColor,
                               position2D::Vector2D centerPoint):
        Entity(centerPoint), generator(arcHeight, centerPoint, particleColor), partColor(particleColor) {
    particles = particleNum;
    rate = generationRate;
    particleSize = partSize;
    this->length = length;
    this->arcAngle = arcAngle;



}

void ParticleSystem::draw() {
    for (Particle &p: particleEntities) {
        p.draw();
    }
}
void ParticleSystem::update() {

    for (Particle &p: particleEntities) {
        p.update();
    }

    if (increment < rate) {
        increment++;
    } else if (particles > 0 and canDraw) {
        increment = 0;
        position2D::Vector2D v = generator.getPointOnEdge(arcAngle);
        int x = cosf(v.rotationAngle * M_PI / 180) * 2;
        int y = sinf(v.rotationAngle * M_PI / 180) * 2;
        particleEntities.emplace_back(Particle(particleSize, v, position2D::Vector2D(0,0,v.rotationAngle), partColor, length));
        particles--;
    }
}

void ParticleSystem::start() {
    canDraw = true;
}

void ParticleSystem::stop() {
    canDraw = false;
}