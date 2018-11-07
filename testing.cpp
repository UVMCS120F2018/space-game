////
//// Created by Zach Bernstein on 9/18/18.
////
//
//#include <cmath>
//#include <utility>
//#include "starship.h"
//
//using namespace ship;
//
//namespace testObject {
//    StarSystem testSystem1("Test System", coordinate {5, -3.2, 287}, "none", "high tech", "parliament", 18000000l);
//    StarSystem testSystem2("Test System", coordinate {2987, -8, -39}, "empire", "farming", "democracy", 50000l);
//    Voyager voyager = Voyager(32., 12., 38., testObject::testSystem1, EXPLORATION);
//    Viper viper = Viper(32., 12., 38., testObject::testSystem1, COMBAT);
//    crewmember jackie {"jackie horton", NAVIGATOR};
//    crewmember lisa {"lisa dion", PILOT};
//}
//
//// testing utility function
//double trunc2f(double n) {
//    return (int)(n * 100) / 100.;
//}
//
//// test cases
//bool testSystemCsvImport() {
//    std::vector<StarSystem> systems;
//    readStarSystemCsv(systems);
//
//    return systems.size() == 24;
//}
//
//bool viperTestConstructorDefault() {
//    Viper ship = Viper();
//
//    return ship.getFuelCapacity() == 10.
//           && ship.getFuelLevel() == 10.
//           && ship.getJumpRange() == 5.
//           && ship.getCurrentLocation().getCoordinates() == coordinate {0, 0, 0}
//           && ship.getRole() == GENERAL
//           && ship.areWeaponsDeployed() == false;
//
//}
//bool viperTestConstructorParameters() {
//    Viper ship = Viper(100., 80., 30., StarSystem("Sol", coordinate {0, 0, 0}), GENERAL);
//
//    return ship.getFuelCapacity() == 100.
//           && ship.getFuelLevel() == 80.
//           && ship.getJumpRange() == 30.
//           && ship.getCurrentLocation().getCoordinates() == coordinate {0, 0, 0}
//           && ship.getRole() == GENERAL
//           && ship.areWeaponsDeployed() == false;
//}
//bool voyagerTestConstructorDefault() {
//    Voyager ship = Voyager();
//
//    return ship.getFuelCapacity() == 10.
//           && ship.getFuelLevel() == 10.
//           && ship.getJumpRange() == 5.
//           && ship.getCurrentLocation().getCoordinates() == coordinate {0, 0, 0}
//           && ship.getRole() == GENERAL;
//
//}
//bool voyagerTestConstructorParameters() {
//    Voyager ship = Voyager(100., 80., 30., StarSystem("Sol", coordinate {0, 0, 0}), GENERAL);
//
//    return ship.getFuelCapacity() == 100.
//           && ship.getFuelLevel() == 80.
//           && ship.getJumpRange() == 30.
//           && ship.getCurrentLocation().getCoordinates() == coordinate {0, 0, 0}
//           && ship.getRole() == GENERAL;
//}
//
//bool starshipTestGetFuelCapacity(StarShip &ship, double test_capacity) {
//    return ship.getFuelCapacity() == test_capacity;
//}
//bool starshipTestGetFuelLevel(StarShip &ship, double test_level) {
//    return ship.getFuelLevel() == test_level;
//}
//bool starshipTestGetJumpRange(StarShip &ship, double test_range) {
//    return ship.getJumpRange() == test_range;
//}
//bool starshipTestGetPosition(StarShip &ship, coordinate test_position) {
//    return ship.getCurrentLocation().getCoordinates() == test_position;
//}
//bool starshipTestGetRole(StarShip &ship, enum shipType role) {
//    return ship.getRole() == role;
//}
//bool starshipTestAddFuel(StarShip &ship, double testAmount) {
//    double prevLevel = ship.getFuelLevel();
//    ship.addFuel(testAmount);
//    if (prevLevel + testAmount >= ship.getFuelCapacity())
//        return ship.getFuelLevel() == ship.getFuelCapacity();
//    else
//        return ship.getFuelLevel() == prevLevel + testAmount;
//}
//bool starshipTestAddCrewmember(StarShip &ship, crewmember member) {
//    ship.addCrewmember(member);
//    return ship.getCrew().back() == member;
//}
//bool viperTestGetWeaponsDeployed(Viper &ship, bool currentStatus) {
//    return ship.areWeaponsDeployed() == currentStatus;
//}
//bool viperTestToggleWeaponsDeployed(Viper &ship, bool initialState) {
//    ship.toggleWeaponsDeployed();
//    return (!initialState) == ship.areWeaponsDeployed();
//}
//bool voyagerTestScoopFuel() {
//    Voyager ship = Voyager(15., 0., 5., StarSystem("test system", coordinate {0,0,0}), EXPLORATION);
//    ship.scoopFuel();
//    return ship.getFuelLevel() == ship.getFuelCapacity();
//}
//bool voyagerTestJumpWithinRange() {
//    Voyager ship = Voyager(32., 12., 38., StarSystem("original system", coordinate(5, -3.2, 287)), EXPLORATION);
//    coordinate testPosition = coordinate(8, 267.98, 1.874);
//    // dist: 393.502768
//    // fuel depletion: dist / 38 = 10.355336
//    bool result = ship.jump(StarSystem("new system", testPosition));
//
//    return result
//           && ship.getCurrentLocation().getCoordinates() == testPosition
//           && trunc2f(ship.getFuelLevel()) == trunc2f(12 - 10.355336);
//}
//bool voyagerTestJumpOutOfRange() {
//    Voyager ship = Voyager(32., 12., 38., StarSystem("original system", coordinate(0, 0, 0)), EXPLORATION);
//    coordinate testPosition = coordinate(10, 8, -1376.1);
//    coordinate originalPosition = ship.getCurrentLocation().getCoordinates();
//    double originalFuelLevel = ship.getFuelLevel();
//
//    // dist: 1376.159587
//    // fuel depletion: dist / 38 = 36.2147259737
//    bool result = ship.jump(StarSystem("new system", testPosition));
//
//    return !result
//           && ship.getCurrentLocation().getCoordinates() == originalPosition
//           && ship.getFuelLevel() == originalFuelLevel;
//}
//bool viperTestJumpWithinRange() {
//    Viper ship = Viper(32., 12., 38., StarSystem("original system", coordinate(5, -3.2, 287)), COMBAT);
//    coordinate testPosition = coordinate(8, 267.98, 1.874);
//    // dist: 393.502768
//    // fuel depletion: dist / 38 = 10.355336
//    bool result = ship.jump(StarSystem("new system", testPosition));
//
//    return result
//           && ship.getCurrentLocation().getCoordinates() == testPosition
//           && trunc2f(ship.getFuelLevel()) == trunc2f(12 - 10.355336);
//}
//bool viperTestJumpOutOfRange() {
//    Viper ship = Viper(32., 12., 38., StarSystem("original system", coordinate(0, 0, 0)), COMBAT);
//    coordinate testPosition = coordinate(10, 8, -1376.1);
//    coordinate originalPosition = ship.getCurrentLocation().getCoordinates();
//    double originalFuelLevel = ship.getFuelLevel();
//
//    // dist: 1376.159587
//    // fuel depletion: dist / 38 = 36.2147259737
//    bool result = ship.jump(StarSystem("new system", testPosition));
//
//    return !result
//           && ship.getCurrentLocation().getCoordinates() == originalPosition
//           && ship.getFuelLevel() == originalFuelLevel;
//}
//bool viperTestJumpWeaponsDeployed() {
//    Viper ship = Viper(32., 12., 38., StarSystem("original system", coordinate(5, -3.2, 287)), COMBAT);
//    ship.toggleWeaponsDeployed();
//    coordinate testPosition = coordinate(8, 267.98, 1.874);
//    // dist: 393.502768
//    // fuel depletion: dist / 38 = 10.355336
//    bool result = ship.jump(StarSystem("new system", testPosition));
//
//    return !result;
//}
//
//bool starSystemTestConstructorTwoParameters() {
//    StarSystem sys = StarSystem("test system", coordinate {5, 5, 5});
//    return sys.getName() == "test system" && sys.getCoordinates() == coordinate {5, 5, 5};
//}
//bool starSystemTestConstructorSixParameters() {
//    StarSystem sys = StarSystem("test system", coordinate {0, 5, 10}, "none", "high tech", "monarchy", 5000l);
//    return sys.getName() == "test system"
//        && sys.getCoordinates() == coordinate {0, 5, 10}
//        && sys.getAllegiance() == "none"
//        && sys.getEconomy() == "high tech"
//        && sys.getGovernment() == "monarchy"
//        && sys.getPopulation() == 5000l;
//}
//
//bool starSystemTestGetName(StarSystem &sys, const std::string &name) {
//    return sys.getName() == name;
//}
//bool starSystemTestGetCoordinates(StarSystem &sys, coordinate coord) {
//    return sys.getCoordinates() == coord;
//}
//bool starSystemTestGetAllegiance(StarSystem &sys, const std::string &allegiance) {
//    return sys.getAllegiance() == allegiance;
//}
//bool starSystemTestGetEconomy(StarSystem &sys, const std::string &economy) {
//    return sys.getEconomy() == economy;
//}
//bool starSystemTestGetGovernment(StarSystem &sys, const std::string &government) {
//    return sys.getGovernment() == government;
//}
//bool starSystemTestGetPopulation(StarSystem &sys, long population) {
//    return sys.getPopulation() == population;
//}
//bool starSystemTestOperatorEquals(StarSystem &sys1, StarSystem &sys2, bool expected) {
//    return (sys1 == sys2) == expected;
//}
//bool starSystemTestOperatorNotEquals(StarSystem &sys1, StarSystem &sys2, bool expected) {
//    return (sys1 != sys2) == expected;
//}
//bool starSystemTestCalculateDistance() {
//    coordinate c1 = coordinate(5, 8, 98);
//    coordinate c2 = coordinate(120, 228, -151);
//    StarSystem sys1 = StarSystem("system 1", c1);
//    StarSystem sys2 = StarSystem("system 2", c2);
//
//    return StarSystem::calculateDistance(sys1, sys2) == std::sqrt(
//              std::pow(std::get<0>(c2) - std::get<0>(c1), 2)
//            + std::pow(std::get<1>(c2) - std::get<1>(c1), 2)
//            + std::pow(std::get<2>(c2) - std::get<2>(c1), 2));
//}
//
//bool crewmemberTestOperatorEquals(crewmember cm1, crewmember cm2, bool expected) {
//    return (cm1 == cm2) == expected;
//}
//
//
//int main() {
//
//    std::cout << "######## testing constructors ############" << std::endl;
//    std::cout << "Viper(0 parameters)                :: " << (viperTestConstructorDefault()            ? "pass" : "fail") << std::endl;
//    std::cout << "Viper(5 parameters)                :: " << (viperTestConstructorParameters()         ? "pass" : "fail") << std::endl;
//    std::cout << "Voyager(0 parameters)              :: " << (voyagerTestConstructorDefault()          ? "pass" : "fail") << std::endl;
//    std::cout << "Voyager(5 parameters)              :: " << (voyagerTestConstructorParameters()       ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem(2 parameters)           :: " << (starSystemTestConstructorTwoParameters() ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem(6 parameters)           :: " << (starSystemTestConstructorSixParameters() ? "pass" : "fail") << std::endl;
//
//    std::cout << std::endl;
//
//
//    std::cout << "######## testing getters / setters #######" << std::endl;
//    std::cout << "StarShip::getFuelCapacity()        :: " << (starshipTestGetFuelCapacity(testObject::voyager, 32.)                                     ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::getFuelLevel()           :: " << (starshipTestGetFuelLevel(testObject::voyager, 12.)                                        ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::getJumpRange()           :: " << (starshipTestGetJumpRange(testObject::voyager, 38.)                                        ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::getCurrentLocation()     :: " << (starshipTestGetPosition(testObject::voyager, testObject::testSystem1.getCoordinates())    ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::getRole()                :: " << (starshipTestGetRole(testObject::voyager, EXPLORATION)                                     ? "pass" : "fail") << std::endl;
//
//    std::cout << "StarShip::addFuel()  [success]     :: " << (starshipTestAddFuel(testObject::voyager, 8.)                                              ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::addFuel()  [overflow]    :: " << (starshipTestAddFuel(testObject::voyager, 40.)                                             ? "pass" : "fail") << std::endl;
//    std::cout << "StarShip::addCrewmember()          :: " << (starshipTestAddCrewmember(testObject::voyager, testObject::jackie)                        ? "pass" : "fail") << std::endl;
//
//    std::cout << "Viper::areWeaponsDeployed()        :: " << (viperTestGetWeaponsDeployed(testObject::viper, false)                                     ? "pass" : "fail") << std::endl;
//    std::cout << "Viper::toggleWeaponsDeployed()     :: " << (viperTestToggleWeaponsDeployed(testObject::viper, testObject::viper.areWeaponsDeployed()) ? "pass" : "fail") << std::endl;
//
//    std::cout << "StarSystem::getName()              :: " << (starSystemTestGetName(testObject::testSystem1, "Test System")                             ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::getCoordinates()       :: " << (starSystemTestGetCoordinates(testObject::testSystem1, coordinate {5, -3.2, 287})          ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::getAllegiance()        :: " << (starSystemTestGetAllegiance(testObject::testSystem1, "none")                              ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::getEconomy()           :: " << (starSystemTestGetEconomy(testObject::testSystem1, "high tech")                            ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::getGovernment()        :: " << (starSystemTestGetGovernment(testObject::testSystem1, "parliament")                        ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::getPopulation()        :: " << (starSystemTestGetPopulation(testObject::testSystem1, 18000000l)                           ? "pass" : "fail") << std::endl;
//
//    std::cout << std::endl;
//
//
//    std::cout << "######## testing overloaded operators ####" << std::endl;
//    std::cout << "StarSystem::operator==() [true]    :: " << (starSystemTestOperatorEquals(testObject::testSystem1, testObject::testSystem1, true)      ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::operator==() [false]   :: " << (starSystemTestOperatorEquals(testObject::testSystem1, testObject::testSystem2, false)     ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::operator!=() [true]    :: " << (starSystemTestOperatorNotEquals(testObject::testSystem1, testObject::testSystem2, true)   ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::operator!=() [false]   :: " << (starSystemTestOperatorNotEquals(testObject::testSystem1, testObject::testSystem1, false)  ? "pass" : "fail") << std::endl;
//    std::cout << "crewmember::operator==() [true]    :: " << (crewmemberTestOperatorEquals(testObject::jackie, testObject::jackie, true)                ? "pass" : "fail") << std::endl;
//    std::cout << "crewmember::operator==() [false]   :: " << (crewmemberTestOperatorEquals(testObject::jackie, testObject::lisa, false)                 ? "pass" : "fail") << std::endl;
//
//    std::cout << std::endl;
//
//
//    std::cout << "######## testing other methods# ##########" << std::endl;
//    std::cout << "readStarSystemCsv()                :: " << (testSystemCsvImport()             ? "pass" : "fail") << std::endl;
//    std::cout << "Voyager::scoopFuel()               :: " << (voyagerTestScoopFuel()            ? "pass" : "fail") << std::endl;
//    std::cout << "Voyager::jump() [within range]     :: " << (voyagerTestJumpWithinRange()      ? "pass" : "fail") << std::endl;
//    std::cout << "Voyager::jump() [out of range]     :: " << (voyagerTestJumpOutOfRange()       ? "pass" : "fail") << std::endl;
//    std::cout << "Viper::jump()   [within range]     :: " << (viperTestJumpWithinRange()        ? "pass" : "fail") << std::endl;
//    std::cout << "Viper::jump()   [out of range]     :: " << (viperTestJumpOutOfRange()         ? "pass" : "fail") << std::endl;
//    std::cout << "Viper::jump()   [weapons deployed] :: " << (viperTestJumpWeaponsDeployed()    ? "pass" : "fail") << std::endl;
//    std::cout << "StarSystem::calculateDistance()    :: " << (starSystemTestCalculateDistance() ? "pass" : "fail") << std::endl;
//
//
//    return 0;
//}