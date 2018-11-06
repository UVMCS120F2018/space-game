//
// Created by Zach Bernstein on 9/19/18.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "star_system.h"
using namespace std;

void readStarSystemCsv(vector<StarSystem> &systems) {
    ifstream datafile;
    datafile.open("../systems.csv");

    if (!datafile) { // print error if file not found
        cout << "error opening file" << endl;
        return;
    }

    // discard header row
    string header;
    getline(datafile, header);

    // initialize input variables
    string name, allegiance, economy, government, junk;
    double x, y, z;
    long population;
    char comma;

    // read file
    while (datafile && datafile.peek() != EOF) {
        getline(datafile, name, ',');

        datafile >> x >> comma;
        datafile >> y >> comma;
        datafile >> z >> comma;
        if (!datafile) {datafile.clear();}

        getline(datafile, allegiance, ',');
        getline(datafile, economy, ',');
        getline(datafile, government, ',');

        datafile >> population;
        if (!datafile) {datafile.clear();}

        getline(datafile, junk); // clear newline char

        StarSystem sys(name, coordinate {x, y, z}, allegiance, economy, government, population);
        systems.push_back(sys);
    }

    datafile.close();
}

StarSystem::StarSystem(std::string name, coordinate location) {
    this->name = std::move(name);
    std::tie(this->x, this->y, this->z) = location;
    this->allegiance = nullopt;
    this->economy = nullopt;
    this->government = nullopt;
    this->population = 0l;
}
StarSystem::StarSystem(std::string name, coordinate location, string allegiance, string economy, string government, long population)
    : StarSystem(std::move(name), location) {
    this->allegiance = make_optional(std::move(allegiance));
    this->economy = make_optional(std::move(economy));
    this->government = make_optional(std::move(government));
    this->population = population;
}

string StarSystem::getName() const {
    return name;
}
coordinate StarSystem::getCoordinates() const {
    return coordinate {x, y, z};
}
string StarSystem::getAllegiance() const {
    return allegiance ? *allegiance : "";
}
string StarSystem::getEconomy() const {
    return economy ? *economy : "";
}
string StarSystem::getGovernment() const {
    return government ? *government : "";
}
long StarSystem::getPopulation() const {
    return population;
}

double StarSystem::calculateDistance(const StarSystem &sys1, const StarSystem &sys2) {
    return std::sqrt(std::pow(sys2.x - sys1.x, 2) + std::pow(sys2.y - sys1.y, 2) + std::pow(sys2.z - sys1.z, 2));
}

std::ostream& operator << (std::ostream &outs, const StarSystem &system) {
    outs << system.name << endl
         << "=================================" << endl
         << " coordinates: " << system.x << " / " << system.y << " / " << system.z << endl
         << "  population: " << system.population << endl;

    if (system.allegiance)
        outs << "  allegiance: " << *system.allegiance << endl;
    if (system.economy)
        outs << "  economy: " << *system.economy << endl;
    if (system.government)
        outs << "  government: " << *system.government << endl;

    outs << endl;

    return outs;
}
bool operator == (const StarSystem &lhs, const StarSystem &rhs) {
    return lhs.getCoordinates() == rhs.getCoordinates() && lhs.getName() == rhs.getName();
}
bool operator != (const StarSystem &lhs, const StarSystem &rhs) {
    return !(lhs == rhs);
}
