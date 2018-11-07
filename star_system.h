//
// Created by Zach Bernstein on 9/19/18.
//

#ifndef PROJECT2_SYSTEM_H
#define PROJECT2_SYSTEM_H

#include <iostream>
#include <vector>
#include <experimental/optional>

using namespace std::experimental;

// shorthand for coordinate tuple
typedef std::tuple<double, double, double> coordinate;
typedef optional<std::string> optString;

/** StarSystem class
 *
 * represents a populated star system
 */
class StarSystem {
private:
    //// fields
    std::string name;
    double x;
    double y;
    double z;
    optString allegiance;
    optString economy;
    optString government;
    long population;
public:
    //// constructors
    /*default*/
    StarSystem();
    /** simple constructor
     *
     * creates a star system object with the given name and location, and all other misc fields uninitialized.
     *
     * @param name - the name of the star system
     * @param location - the coordinates of the star system
     */
    StarSystem(std::string name, coordinate location);
    /** full constructor
     *
     * creates a star system object with all attributes detailed.
     *
     * @param name - the name of the star system
     * @param location - the coordinates of the star system
     * @param allegiance - the allegiance of the star system's major faction
     * @param economy - the main driver of the star system's economy
     * @param government - the type of government of the star system
     * @param population - the population of the star system
     */
    StarSystem(std::string name, coordinate location, std::string allegiance, std::string economy, std::string government, long population);

    //// getters
    /**
     * @return the value of the field
     */
    std::string getName() const;
    coordinate getCoordinates() const;
    std::string getAllegiance() const;
    std::string getEconomy() const;
    std::string getGovernment() const;
    long getPopulation() const;

    //// overloaded operators
    /**
     * prints a nicely formatted representation of the star system to the output stream.
     *
     * @param outs - an ostream (i.e. cout)
     * @param system - the star system to print
     * @return the modified ostream
     */
    friend std::ostream& operator << (std::ostream &outs, const StarSystem &system);
    /**
     * checks for equality between two star systems
     *
     * @param lhs - a star system
     * @param rhs - a star system
     * @return whether or not the two star systems are equal
     */
    friend bool operator == (const StarSystem &lhs, const StarSystem &rhs);
    /**
     * checks for inequality between two star systems
     *
     * @param lhs - a star system
     * @param rhs - a star system
     * @return whether or not the two star systems are not equal
     */
    friend bool operator != (const StarSystem &lhs, const StarSystem &rhs);

    //// methods
    /**
     * calculate the distance in 3D space between two star systems
     *
     * @param sys1 - a star system
     * @param sys2 - a star system
     * @return the distance in light years between the two star systems
     */
    static double calculateDistance(const StarSystem &sys1, const StarSystem &sys2);
};

/**
 * read in data from systems.csv file and creates star system objects in given vector
 *
 * @param systems - an empty StarSystem vector
 */
void readStarSystemCsv(std::vector<StarSystem> &systems);

#endif //PROJECT2_SYSTEM_H
