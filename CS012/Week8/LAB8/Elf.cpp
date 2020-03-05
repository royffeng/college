#include <iostream>
#include "Character.h"
#include "Elf.h"

using namespace std;

Elf::Elf(const string &hname, double hp, double attack, string allegiance) : Character(ELF, hname, hp, attack), allegiance(allegiance) {}

void Elf::attack(Character &chrct) {
    if(chrct.getType() == ELF) {
        Elf &opponent = dynamic_cast<Elf &>(chrct);
        if(allegiance == opponent.allegiance) {
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << ".\n";
            cout << "They are both members of the " << allegiance << " family.\n";
        }else {
            double totalDamage = (health / MAX_HEALTH) * attackStrength;
            chrct.damage(totalDamage);
            cout << "Elf " << name << " shoots an arrow at " << chrct.getName() << " --- TWANG!!\n";
            cout << chrct.getName() << " takes " << totalDamage << " damage.\n";
        }
    }else {
        double totalDamage = (health / MAX_HEALTH) * attackStrength;
        chrct.damage(totalDamage);
        cout << "Elf " << name << " shoots an arrow at " << chrct.getName() << " --- TWANG!!\n";
        cout << chrct.getName() << " takes " << totalDamage << " damage.\n";
    }
}
