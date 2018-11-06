//
// Created by Ethan Nerney on 11/2/18.
//

#include "StarSystem.h"
#include "RandNum.h"

using namespace position2D;

StarSystem::StarSystem(int particleNums, int particleRate, int boundsWidth, int boundsHeight,
                       position2D::Vector2D point): Entity(point) {
    particles = particleNums;
    rate = particleRate;
    width = boundsWidth;
    height = boundsHeight;
}

void StarSystem::update() {
    for (StarBoi &s: starBois) {
        s.update();
    }

    if (increment < rate) {
        increment++;
    } else if (particles > 0){
        increment = 0;
        RandNum r;

        // create the starboi


        int ri,ru;
        do {
            ri = r.getInt(-5, 5);
            ru = r.getInt(-5, 5);
        } while (ri == 0 and ru == 0);

        int rad = r.getInt(1, 4);

        starBois.emplace_back(StarBoi(ri * 3, ru * 3, rad, height, width, Vector2D(width / 2, height / 2)));

        particles --;
    }
}

void StarSystem::draw() {
    for (StarBoi &s: starBois) {
        s.draw();
    }
}

