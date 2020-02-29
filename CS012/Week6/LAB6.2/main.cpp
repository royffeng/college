#include "IntVector.h"
#include <iostream>
using namespace std;

int main() {
    IntVector v(8, 7); 
    cout << "Size Function Test: " << endl;
    cout << "Size: " << v.size() << endl << endl;
    cout << "Capacity Function Test: " << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;
    
    IntVector x;
    
    cout << "Empty Function Test: " << endl;
    if(x.empty() == true) {
        cout << "Empty Function correctly returned false when size and capacity was 0.\n";
    }
    cout << endl;
    
    cout << "Destructor Test: \n";
    IntVector* z = new IntVector();
    delete z;
    cout << endl << endl;
    
    cout << "At Function Test with Valid Index: \n";
    cout << v.at(1) << endl << endl;
    cout << "At Function Test with Invalid Index: \n";
    cout << v.at(7) << endl;
    
    return 0;
}
