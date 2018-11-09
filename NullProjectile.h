//
// Created by Ethan Nerney on 11/9/18.
//

#ifndef SPACE_GAME_NULLPROJECTILE_H
#define SPACE_GAME_NULLPROJECTILE_H


#include "Projectile.h"

class NullProjectile: public Projectile {
public:
    NullProjectile();

    void update() override;
    void draw() override;
};


#endif //SPACE_GAME_NULLPROJECTILE_H
