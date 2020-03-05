#include <string>

using namespace std;

#ifndef ELF_H
#define ELF_H

class Elf: public Character {
    public:
        Elf(const string &, double, double, string);
        void attack(Character &opponent) override;
    
    private:
        string allegiance;
};

#endif
