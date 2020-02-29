#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string &, const char &);


int main() {
    string filename;
    char ch;
    int chCnt = 0;
    
    cout << "Enter the name of the input file: ";
    cin >> filename;
    cout << endl;
    cout << "Enter a character: ";
    cin.ignore(); // ignores newline left in stream after previous input statement
    cin.get(ch);
    cout << endl;

    chCnt = charCnt(filename, ch);   
    cout << "# of " << ch << "'s: " << chCnt << endl;
   
    return 0;
}

// Place charCnt implementation here
int charCnt(const string & filename, const char &ch){
    ifstream inFS;
    int counter = 0;
    string temp;
    
    inFS.open(filename);
    
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        
        exit(1);
    }
   
//lol none of this worked so i guess im gonna use getline :(
//     while(inFS >> tempAdd){
//         if(tempAdd == ch){
//             counter++;
//         }
//     }
    
    while(getline(inFS, temp)){
        for(unsigned int i = 0; i < temp.size(); i++){
            if(temp.at(i) == ch){
                counter++;
            }
        }
    }
    
    return counter;
}
