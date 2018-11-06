//
// Created by Zach Bernstein on 9/18/18.
//

#ifndef PROJECT2_STARSHIP_H
#define PROJECT2_STARSHIP_H

#include <iostream>
#include <vector>
#include "star_system.h"

//// enum types
enum shipType { GENERAL, COMBAT, EXPLORATION, TRADING, RESEARCH };
enum job { PILOT, GUNNER, NAVIGATOR, MECHANIC, COOK, MEDIC, ENGINEER, MORAL_SUPPORT };

/** crewmember struct
 *
 * represents a crewmember on board a ship
 */
struct crewmember {
    //// fields
    std::string name;
    job specialty;

    //// overloaded operators
    /**
     * test if two crewmember objects are equal
     *
     * @param lhs - a crewmember object
     * @param rhs - a crewmember object
     * @return whether or not the two crewmember objects are equal
     */
    friend bool operator == (crewmember &lhs, crewmember &rhs) {
        return lhs.name == rhs.name && lhs.specialty == rhs.specialty;
    }
    /**
     * print a nicely formatted representation of crewmember to output stream
     *
     * @param outs - an ostream (i.e. cout)
     * @param cm - the crewmember to print a representation of
     * @return the modified ostream object
     */
    friend std::ostream& operator << (std::ostream &outs, crewmember &cm) {
        std::string specialty;
        switch (cm.specialty) {
            case PILOT:         specialty = "pilot";         break;
            case GUNNER:        specialty = "gunner";        break;
            case NAVIGATOR:     specialty = "navigator";     break;
            case MECHANIC:      specialty = "mechanic";      break;
            case COOK:          specialty = "cook";          break;
            case MEDIC:         specialty = "medic";         break;
            case ENGINEER:      specialty = "engineer";      break;
            case MORAL_SUPPORT: specialty = "moral support"; break;
        }

        outs << cm.name << " (" << specialty << ")";
        return outs;
    }
};

namespace ship {
    /** StarShip class (abstract)
     *
     * represents a starship that can travel between systems
     */
    class StarShip {
    protected:
        //// fields
        double jumpRange;
        double fuelLevel;
        double fuelCapacity;
        StarSystem location;
        shipType role;
        std::vector<crewmember> crew;
        bool weaponsDeployed;

    public:
        //// constructors
        /** default constructor
         *
         * sets fuel capacity and level to 10, jump range to 5, star system to Sol,
         * role to General, and crew to empty
         */
        StarShip();
        /** full constructor
         *
         * @param capacity - the fuel capacity of the ship (>0)
         * @param level - the current fuel level of the ship (>0, ≤ fuel capacity)
         * @param jumpRange - the jump range per tonne of fuel (>0)
         * @param position - the current location of the ship
         * @param role - the role that the starship is optimized to perform
         */
        StarShip(double capacity, double level, double jumpRange, StarSystem position, enum shipType role);

        //// destructor
        virtual ~StarShip();

        //// getters
        /**
         *
         * @return - the value of the field
         */
        double getJumpRange() const;
        double getFuelLevel() const;
        double getFuelCapacity() const;
        StarSystem getCurrentLocation() const;
        enum shipType getRole() const;
        std::vector<crewmember> getCrew() const;
        virtual bool areWeaponsDeployed() const = 0;


        //// setters
        /**
         * @param amount - the amount of fuel to add to the tank (>0)
         */
        void addFuel(double amount);
        /**
         * @param newMember - the crew member to add to the crew roster
         */
        void addCrewmember(crewmember newMember);
        /**
         * toggle the status of weapon deployment
         */
        virtual void toggleWeaponsDeployed() = 0;

        //// other methods
        /**
         * uses fuel to jump to the specified star system
         *
         * @param newSystem - the system to jump to
         * @return whether or not the jump was successful
         */
        virtual bool jump(StarSystem newSystem) = 0;
        /**
         * creates a nicely formatted string representing the starship's current status
         * @return a string representing ship status
         */
        std::string printStatus();
        /**
         * Use a fuel scoop to refill the fuel tank.
         */
        virtual void scoopFuel() = 0;

    };

    /**
     * A StarShip that specializes in exploration.
     */
    class Voyager : public StarShip {
    public:
        /**
         * Constructors & Destructors
         */
        Voyager();
        Voyager(double capacity, double level, double jumpRange, const StarSystem &position, enum shipType role);
        ~Voyager() override;

        //// override methods in parent
        void scoopFuel() override;
        bool areWeaponsDeployed() const override;
        void toggleWeaponsDeployed() override;
        bool jump(StarSystem newSystem) override;
    };


    /**
     * A StarShip that specializes in combat.
     */
    class Viper : public StarShip {
    public:
        /**
         * Constructors & Destructors
         */
        Viper();
        Viper(double capacity, double level, double jumpRange, StarSystem position, enum shipType role);
        ~Viper() override;

        //// override methods in parent
        void scoopFuel() override;
        bool areWeaponsDeployed() const override;
        void toggleWeaponsDeployed() override;
        bool jump(StarSystem newSystem) override;
    };
}


//// overloaded operators
/**
 * returns a technical overview of the current state of the starship object
 *
 * @param outs - an ostream (i.e. cout)
 * @param ship - the ship object to print to the ostream
 * @return the modified ostream
 */
std::ostream& operator << (std::ostream &outs, const ship::StarShip &ship);


#endif //PROJECT2_STARSHIP_H
