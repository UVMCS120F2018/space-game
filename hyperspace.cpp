//
// Created by Ethan Nerney on 11/2/18.
//

#include "hyperspace.h"
#include "engine-stuff/rand_num.h"

using namespace position2D;

HyperSpace::HyperSpace(int particleNums, int particleRate, int boundsWidth, int boundsHeight,
                       position2D::Vector2D point): Entity(point), c(15,point,colorGraphics::BLACK) {
    particles = particleNums;
    rate = particleRate;
    width = boundsWidth;
    height = boundsHeight;
}

void HyperSpace::update() {
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

void HyperSpace::draw() {
    for (StarBoi &s: starBois) {
        s.draw();
    }

    c.draw();


}

