#include "Character.h"

using namespace std;

//constructor
Character::Character(HeroType hero, const string &hname, double hp, double attack) : type(hero), name(hname), health(hp), attackStrength(attack) {}

//getter function for hero type
HeroType Character::getType() const {
    return type;
}

//getter function for hero name
const string &Character::getName() const {
    return name;
}

//getter function for hero hp
int Character::getHealth() const {
    return static_cast<int>(health);
}

//setter function for hp
void Character::setHealth(double hp) {
    health = hp;
}

//health updater function, decrements damage value from hp
void Character::damage(double dmg) {
    health -= dmg;
}

//function returns a bool determining if character is still alive
bool Character::isAlive() const {
    if(health > 0) {
        return true;
    }
    
    return false;
}
