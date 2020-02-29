#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here
//Default constructor
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

//Constructor with one parameter
Rational::Rational(int numerator) {
    this->numerator = numerator;
    denominator = 1;
}

//Constructor with two parameters
Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

//Add function
const Rational Rational::add(const Rational &ratios) const {
    Rational add;
    add.numerator = (numerator * ratios.denominator) + (denominator * ratios.numerator);
    add.denominator = (denominator * ratios.denominator);
    
    return add;
}

//Subtract function
const Rational Rational::subtract(const Rational &ratios) const {
    Rational subtract;
    subtract.numerator = (numerator * ratios.denominator) - (denominator * ratios.numerator);
    subtract.denominator = (denominator * ratios.denominator);
    
    return subtract;
}

//Multiply function
const Rational Rational::multiply(const Rational &ratios) const {
    Rational multiply;
    multiply.numerator = (numerator * ratios.numerator);
    multiply.denominator = (denominator * ratios.denominator);
    
    return multiply;
}

//Divide function
const Rational Rational::divide(const Rational &ratios) const {
    Rational divide;
    divide.numerator = (numerator * ratios.denominator);
    divide.denominator = (ratios.numerator * denominator);
    
    return divide;
}

//Simplify function
void Rational::simplify() {
    int gcdVal = gcd(numerator, denominator);
    numerator /= gcdVal;
    denominator /= gcdVal;
}

//Display function
void Rational::display() const {
    cout << numerator << " / " << denominator;
}

//gcd function
int Rational::gcd(int numerator, int denominator) const {
    if(denominator == 0) {
        return numerator;
    }else {
        return gcd(denominator, numerator % denominator);
    }
//     while(numerator != denominator) {
//         if(a > b) {
//             numerator -= denominator;
//         }else {
//             denominator -= numerator;
//         }
//     }
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}
