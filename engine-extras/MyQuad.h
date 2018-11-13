//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_MYQUAD_H
#define SPACE_STUFF_MYQUAD_H


#include "../engine-stuff/Quadrangle.h"

class MyQuad: public Quadrangle {
private:
    int x;
    int y;
public:
    MyQuad();
    void update() override;
};


#endif //SPACE_STUFF_MYQUAD_H
