//
// Created by Ethan Nerney on 11/1/18.
//

#include "MyQuad.h"

MyQuad::MyQuad(): Quadrangle(100, 100, position2D::Vector2D(150,250), colorGraphics::GREEN) {
    x = 1;
    y = 1;
}
void MyQuad::update() {
    translate(position2D::ROTATE_RIGHT * 10);
    translate(position2D::RIGHT * x * 5);
    translate(position2D::DOWN * y * 5);

    if (centerPoint.x > 500 - (getSide1() / 2) or centerPoint.x < (getSide1() / 2)) {
        x *= -1;
    }
    if (centerPoint.y > 500 - (getSide1() / 2) or centerPoint.y < (getSide1() / 2)) {
        y *= -1;
    }
}