#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {
    IntVector v(4, 7); 
    
    //Test size and capacity
    cout << "New Vector object created with size and cap of 4 and values of 7." << endl;
    cout << "Size Function Test: " << endl;
    cout << "Size: " << v.size() << endl << endl;
    cout << "Capacity Function Test: " << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;    
    
    //Test empty function
    cout << "Empty Function Test: " << endl;
    if(v.empty() == false) {
        cout << "Empty Function correctly returned false.";
        cout << endl;
    }
    cout << endl;
    
    //Test push_back function
    cout << "PUSH_BACK FUNCTION TEST: " << endl;
    cout << "Pushing back value 3." << endl;
    v.push_back(3);
    cout << "Size should now be 5: " << v.size() << endl;
    cout << "Capacity should now be 8: " << v.capacity() << endl;
    cout << "Value at index 4 should now be 3: " << v.at(4) << endl << endl;
    
    //Test insert funtion
    cout << "INSERT FUNCTION TEST: " << endl;
    cout << "Inserting value 77 at index 3." << endl;
    v.insert(3, 77);
    cout << "Size should now be 6: " << v.size() << endl;
    cout << "Capacity should now be 8: " << v.capacity() << endl;
    cout << "Value at index 3 should now be 77: " << v.at(3) << endl << endl;
    
    //Test erase function
    cout << "ERASE FUNCTION TEST: " << endl;
    cout << "Erasing value at index 3." << endl;
    v.erase(3);
    cout << "Value at index 3 should now be 7: " << v.at(3) << endl << endl;
    
    //Test resize function
    cout << "RESIZE TEST" << endl;
    cout << "Resizing vector to 10 with values 9" << endl;
    v.resize(10, 9);
    cout << "Capacity should be 16: " << v.capacity() << endl;
    cout << "Size should be 10: " << v.size() << endl;
    cout << v.at(9) << endl << endl;
    
    //Test pop_back function
    cout << "POP_BACK TEST: " << endl;
    v.pop_back();
    cout << v.at(3) << endl << endl;
    
    //Test clear function
    cout << "CLEAR TEST" << endl;
    v.clear();
    cout << v.at(1) << endl << endl;

}
