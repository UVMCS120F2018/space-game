//
// Created by Ethan Nerney on 11/1/18.
//

#include <math.h>
#include "star_boi.h"
#include "engine-stuff/rand_num.h"

using namespace position2D;
StarBoi::StarBoi(int rise, int run, int r, int boundsHeight, int boundsWidth, position2D::Vector2D point):
        Circle(r, point, colorGraphics::WHITE) {
    this->rise = rise;
    this->run = run;
    height = boundsHeight;
    width = boundsWidth;
    startingRad = r;
}

void StarBoi::update() {

    colorGraphics::RGBColor black(0,0,0);
    colorGraphics::RGBColor white(255,255,255);

//    if ((getCenter().x > (width / 2) - 50 and getCenter().x < (width / 2) + 50) and (getCenter().y > (height / 2) - 50 and
//                                                                                     getCenter().y < (height / 2) + 50)) {
//        setColor(black);
//    } else {
//        setColor(white);
//    }




    if (getCenter().x > 0 and getCenter().x < width and getCenter().y > 0 and getCenter().y < height) {

        translate(Vector2D(run, rise));

        if (increment < max) {
            increment++;
        } else {
            setRadius(getRadius()+1);
            increment = 0;
        }

    } else {
        RandNum r;
        setRadius(startingRad);

        int ri,ru;
        do {
            ri = r.getInt(-5, 5);
            ru = r.getInt(-5, 5);
        } while (ri == 0 or ru == 0);

        rise = ri * 2;
        run = ru * 2;

        setColor(black);
        setPosition(Vector2D(width / 2,height / 2));

    }
}

