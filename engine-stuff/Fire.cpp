//
// Created by Ethan Nerney on 11/2/18.
//

#include "Fire.h"

Fire::Fire(int length, colorGraphics::RGBColor smokeColor, colorGraphics::RGBColor topColor,
           colorGraphics::RGBColor midColor, colorGraphics::RGBColor botColor,
           position2D::Vector2D center): Entity(center), smoke(50, 5, length, 30, 1, 2, smokeColor, position2D::Vector2D(center.x, center.y, -90)),
            top(50, 5, length - 5, 30, 1, 2, topColor,position2D::Vector2D(center.x, center.y, -90)),
            mid(50, 5, length - 10, 30, 1, 2, midColor,position2D::Vector2D(center.x, center.y, -90)), bot(50, 5, length - 15, 30, 1, 2, botColor,position2D::Vector2D(center.x, center.y, -90)){}

void Fire::update() {
    smoke.update();
    top.update();
    mid.update();
    bot.update();
}

void Fire::draw() {
    smoke.draw();
    top.draw();
    mid.draw();
    bot.draw();
}