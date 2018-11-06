//
// Created by Zach Bernstein on 9/19/18.
//
#include <vector>
#include "starship.h"

using namespace std;
using namespace ship;


int main() {
    cout << "   *  .  . *       *    .        .        *   *    ..\n"
            " .    *        .           .      .        .            *\n"
            "    *.   *        .   *   .     *      *        *    .\n"
            "     .          STELLAR EXPLORATION .  *      .        .  *\n"
            "  *     .  .     .*       ..         .      *  .  ..  *\n"
            ".      *       .         *     *            .      *   *\n" << endl;
            // modified from https://www.asciiart.eu/space/stars

    vector<StarSystem> systems;
    readStarSystemCsv(systems);

    StarSystem sol = systems[10];

    vector<shared_ptr<StarShip>> hangar = {
            shared_ptr<StarShip>(new Viper(10., 10., 10., sol, GENERAL)),
            shared_ptr<StarShip>(new Voyager(3., 3., 15., sol, RESEARCH)),
            shared_ptr<StarShip>(new Viper(25., 25., 2.35, sol, COMBAT)),
            shared_ptr<StarShip>(new Voyager(7., 7., 8., sol, TRADING)),
            shared_ptr<StarShip>(new Voyager(9., 9., 17., sol, EXPLORATION))
    };

    cout << "pick your ship:" << endl;
    for (int i = 0; i < hangar.size(); i++) {
        cout << "   (" << i << "): " << *hangar[i] << endl;
    }
    int hangarIdx;
    do {
        cout << "> ";
        cin >> hangarIdx;
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            hangarIdx = -1;
        }
    } while (hangarIdx < 0 || hangarIdx > 4);

    auto userShip = shared_ptr<StarShip>(hangar[hangarIdx]);

    vector<crewmember> lounge = {
            crewmember {"lisa dion", PILOT},
            crewmember {"bob erickson", GUNNER},
            crewmember {"jackie horton", NAVIGATOR},
            crewmember {"byung lee", MEDIC},
            crewmember {"jim eddy", COOK},  // because he makes raspberry pie
            crewmember {"josh bongard", MECHANIC},
            crewmember {"sheila weaver", MORAL_SUPPORT}
    };
    cout << "pick 3 crewmembers: " << endl;

    vector<int> selected;
    for (int i = 0; i < lounge.size(); i++) {
        cout << "   (" << i << "): " << lounge[i] << endl;
    }

    for (int c = 0; c < 3; c++) {
        int crewIdx;
        do {
            cout << "> ";
            cin >> crewIdx;
            if (!cin) {
                cin.clear();
                cin.ignore(100, '\n');
                crewIdx = -1;
            }
            else if (std::find(selected.begin(), selected.end(), crewIdx) != std::end(selected)) {
                cout << "that crewmember is already on board!" << endl;
                crewIdx = -1;
            }
        } while (crewIdx < 0 || crewIdx > 6);

        crewmember cm = lounge[crewIdx];
        selected.push_back(crewIdx);
        userShip->addCrewmember(cm);
        cout << cm.name << " has joined your crew!" << endl;
    }


    cout << "current location: " << sol << endl;

    char choice;
    int systemIdx;
    double fuelAmount;
    bool jumpSuccessful;
    StarSystem currentSystem = sol, targetSystem = sol;
    do {
        cout << endl << "(l)ist systems, (j)ump to a system, (r)efuel, s(c)oop fuel, "
                        "(t)oggle weapons, ship (s)tatus, (q)uit" << endl;
        cout << "> ";
        cin  >> choice;
        switch (choice) {
            case 'l':
                for (int i = 0; i < systems.size(); i++) {
                    cout << "(" << i << ") " << systems[i];
                }
                break;

            case 'j':
                cout << "pick a system to travel to: " << endl;
                do {
                    cout << ">";
                    cin >> systemIdx;
                } while (systemIdx < 0 || systemIdx > 23);

                targetSystem = systems[systemIdx];
                jumpSuccessful = userShip->jump(targetSystem);
                if (jumpSuccessful) {
                    cout << "jump successful! you are now in " << targetSystem.getName() << " with " << userShip->getFuelLevel() << "T of fuel left." << endl;
                    currentSystem = targetSystem;
                }
                else {
                    cout << "couldn't make the jump to " << targetSystem.getName() << ". check to make sure your weapons"
                                                                                      " are retracted and you have enough fuel." << endl;
                }

                break;

            case 'r':
                cout << "amount to refuel: ";
                do {
                    cin >> fuelAmount;
                } while (fuelAmount < 0);
                userShip->addFuel(fuelAmount);
                cout << userShip->printStatus() << endl;
                break;

            case 's':
                cout << "current system: " << currentSystem << endl;
                cout << userShip->printStatus() << endl;
                break;

            case 't':
                userShip->toggleWeaponsDeployed();
                break;

            case 'c':
                userShip->scoopFuel();
                break;

            default:
            case 'q':
                break;

        }
    } while (choice != 'q');

    return 0;
}