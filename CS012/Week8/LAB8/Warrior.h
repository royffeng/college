#include <string>

using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: public Character {
    public:
        Warrior(const string &, double, double, string);
        void attack(Character &opponent) override;
    
    private:
        string allegiance;
};

#endif
