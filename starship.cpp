//

// Created by Zach Bernstein on 9/18/18.
//
#include <iomanip>
#include <sstream>
#include <utility>
#include "starship.h"

using namespace ship;

///// constructors
StarShip::StarShip() : StarShip(10., 10., 5., StarSystem("Sol", coordinate {0, 0, 0}), GENERAL) {}
StarShip::StarShip(double capacity, double level, double jumpRange, StarSystem position, enum shipType role)
        : location(std::move(position)) {
    this->fuelCapacity = capacity > 0 ? capacity : 0.;
    this->fuelLevel = level >= 0 && level <= capacity ? level : 0.;
    this->jumpRange = jumpRange > 0 ? jumpRange : 0.;
    this->role = role;
}

Viper::Viper() : StarShip() {
    this->weaponsDeployed = false;
}
Viper::Viper(double capacity, double level, double jumpRange, StarSystem position, enum shipType role)
        : StarShip(capacity, level, jumpRange, std::move(position), role) {
    this->weaponsDeployed = false;
}

Voyager::Voyager() : StarShip() {}
Voyager::Voyager(double capacity, double level, double jumpRange, const StarSystem &position, enum shipType role)
        : StarShip(capacity, level, jumpRange, position, role) {}

///// destructors
StarShip::~StarShip() = default;
Viper::~Viper() = default;
Voyager::~Voyager() = default;


///// getters
double StarShip::getFuelCapacity() const {
    return this->fuelCapacity;
}
double StarShip::getFuelLevel() const {
    return this->fuelLevel;
}
double StarShip::getJumpRange() const {
    return this->jumpRange;
}
StarSystem StarShip::getCurrentLocation() const {
    return this->location;
}
enum shipType StarShip::getRole() const {
    return this->role;
}
std::vector<crewmember> StarShip::getCrew() const {
    return std::vector<crewmember>(this->crew);
}

bool Voyager::areWeaponsDeployed() const {
    return false;
}
bool Viper::areWeaponsDeployed() const {
    return weaponsDeployed;
}

///// setters
void StarShip::addFuel(double amount) {
    // invalid amount added
    if (amount <= 0)
        return;

    // amount would overflow tank
    if (this->getFuelLevel() + amount >= this->getFuelCapacity()) {
        this->fuelLevel = this->getFuelCapacity();
        return;
    }

    this->fuelLevel += amount;
}
void StarShip::addCrewmember(crewmember newMember) {
    this->crew.push_back(newMember);
}

void Voyager::toggleWeaponsDeployed() {
    std::cout << "no weapons installed!" << std::endl;
}
void Viper::toggleWeaponsDeployed() {
    this->weaponsDeployed = !this->weaponsDeployed;
}

///// other methods
std::string StarShip::printStatus() {
    std::stringstream ss;
    ss  << std::fixed << std::setprecision(1)
        << "fuel: " << std::setw(4) << this->getFuelLevel() << "T / " << std::setw(4) << this->getFuelCapacity() << std::setw(0) << "T" << std::endl
        << "jump range: " << std::setprecision(0) << std::setw(0) << this->getJumpRange() << " LY / T" << std::endl
        << "crew: ";

    for (int i = 0; i < this->getCrew().size(); i++) {
        ss << this->getCrew()[i] << (i == this->getCrew().size() - 1 ? "" : ", ");
    }
    return ss.str();
}

void Voyager::scoopFuel() {
    // top off tank
    this->fuelLevel = this->fuelCapacity;
}
bool Voyager::jump(StarSystem newSystem) {
    // handle not moving
    if (newSystem.getCoordinates() == this->getCurrentLocation().getCoordinates())
        return false;

    double distance = StarSystem::calculateDistance(this->getCurrentLocation(), newSystem);
    double fuelUsage = distance / this->getJumpRange();

    // make sure there is enough fuel to make the jump
    if (fuelUsage > this->getFuelLevel())
        return false;

    // jump
    this->fuelLevel = this->getFuelLevel() - fuelUsage;
    this->location = newSystem;

    return true;
}
void Viper::scoopFuel() {
    std::cout << "no fuel scoop installed!" << std::endl;
}
bool Viper::jump(StarSystem newSystem) {
    // fail if weapons are deployed
    if (this->weaponsDeployed)
        return false;

    // handle not moving
    if (newSystem.getCoordinates() == this->getCurrentLocation().getCoordinates())
        return false;

    double distance = StarSystem::calculateDistance(this->getCurrentLocation(), newSystem);
    double fuelUsage = distance / this->getJumpRange();

    // make sure there is enough fuel to make the jump
    if (fuelUsage > this->getFuelLevel())
        return false;

    // jump
    this->fuelLevel = this->getFuelLevel() - fuelUsage;
    this->location = newSystem;

    return true;
}


///// overloaded operators
std::ostream& operator << (std::ostream &outs, const StarShip &ship) {
    std::string role;
    switch (ship.getRole()) {
        case GENERAL:       role = "general vessel";       break;
        case COMBAT:        role = "combat vessel";        break;
        case EXPLORATION:   role = "exploration vessel";   break;
        case TRADING:       role = "trading vessel";       break;
        case RESEARCH:      role = "research vessel";      break;
    }
    outs << "StarShip<"
         << std::setprecision(3) << ship.getFuelLevel() << "/" << ship.getFuelCapacity() << "t, "
         << std::setprecision(3) << ship.getJumpRange() << "ly/t, "
         << role << ">";

    return outs;
}
