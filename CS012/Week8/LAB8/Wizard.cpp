#include <iostream>
#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &hname, double hp, double attack, int rank) : Character(WIZARD, hname, hp, attack), rank(rank) {}

void Wizard::attack(Character &chrct) {
    if(chrct.getType() == WIZARD) {
        Wizard &opponent = dynamic_cast<Wizard &>(chrct);
        double totalDamage = attackStrength * (static_cast<double>(rank) / opponent.rank);
        opponent.damage(totalDamage);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!\n";
        cout << opponent.getName() << " takes " << totalDamage << " damage.\n";
    }else {
        double totalDamage = attackStrength;
        chrct.damage(totalDamage);
        cout << "Wizard " << name << " attacks " << chrct.getName() << " --- POOF!!\n";
        cout << chrct.getName() << " takes " << totalDamage << " damage.\n";
    }
}
