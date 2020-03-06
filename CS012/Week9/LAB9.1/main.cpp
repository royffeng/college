#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
    //base case, when the string being passed is is either size 1 or 0
    if(s.size() <= 1) {
        return;
    }
    
    //swapping the first and last values
    char temp = s.at(s.length() - 1);
    s.at(s.length() - 1) = s.at(0);
    s.at(0) = temp;
    
    //declare and initialize a new string, substring of current string parameter excluding the first and last letters that have already been swapped
    string newS = s.substr(1, s.length() - 2);
    //recursive call to this function, will swap the substring letters in pairs until the full substring is flipped
    flipString(newS);
    //append the first char that was swapped in first function call, append the recursively swapped substring, append the final char that was swapped in the first function call
    s = s.at(0) + newS + s.at(s.length() - 1);
}
