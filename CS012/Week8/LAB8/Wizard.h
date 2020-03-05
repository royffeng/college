#include <string>

using namespace std;

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: public Character {
    public:
        Wizard(const string &, double, double, int);
        void attack(Character &opponent) override;
    
    private:
        int rank;
};

#endif
