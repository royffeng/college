#include <iostream>
#include "Character.h"
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &hname, double hp, double attack, string allegiance) : Character(WARRIOR, hname, hp, attack), allegiance(allegiance) {}

void Warrior::attack(Character &chrct) {
    if(chrct.getType() == WARRIOR) {
        Warrior &opponent = dynamic_cast<Warrior &>(chrct);
        if(allegiance == opponent.allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << ".\n";
            cout << "They share an allegiance with " << allegiance << ".\n";
        }else {
            double totalDamage = (health / MAX_HEALTH) * attackStrength;
            chrct.damage(totalDamage);
            cout << "Warrior " << name << " attacks " << chrct.getName() << " --- SLASH!!\n";
            cout << chrct.getName() << " takes " << totalDamage << " damage.\n";
        }
    }else {
        double totalDamage = (health / MAX_HEALTH) * attackStrength;
        chrct.damage(totalDamage);
        cout << "Warrior " << name << " attacks " << chrct.getName() << " --- SLASH!!\n";
        cout << chrct.getName() << " takes " << totalDamage << " damage.\n";
    }
}
