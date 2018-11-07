//
// Created by Jeremy Weiland on 11/7/18.
//

#ifndef SPACE_GAME_GAME_H
#define SPACE_GAME_GAME_H

#include <vector>
#include "starship.h"

using namespace std;
using namespace ship;

class Game{
private:
    vector<StarSystem> systems;
    StarSystem sol;
    vector<shared_ptr<StarShip>> hangar;
    shared_ptr<StarShip> userShip;
    vector<crewmember> lounge;

public:
    Game();

    shared_ptr<StarShip> selectShip();

    void selectCrew();

    void play();
};



#endif //SPACE_GAME_GAME_H
