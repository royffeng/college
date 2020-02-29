#include <iostream>
#include "Distance.h"

using namespace std;


Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return ((feet * 12) + inches);
}

double Distance::distanceInFeet() const {
    return ((inches / 12) + feet);
}

double Distance::distanceInMeters() const {
    return (((feet * 12) + inches) * 0.0254);
}

Distance Distance::operator+(const Distance &rhs) const {
    Distance temp = Distance(feet + rhs.feet, inches + rhs.inches);
    
    return temp;
}

Distance Distance::operator-(const Distance &rhs) const {
    Distance temp = Distance(distanceInInches() - rhs.distanceInInches());
    
    return temp;
}

ostream& operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    
    return out;
}

void Distance::init() {
    if (inches < 0) {
        inches *= -1;
    }
    
    while(inches >= 12) {
        inches -= 12;
        feet++;
    }
}
