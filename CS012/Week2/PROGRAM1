#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]){
    
    vector<double> angle;
    vector<double> lift;
    string inputFile;
    double userAngle;
    string doAgain;
    
    inputFile = argv[1];
    
    readData(inputFile, angle, lift);

    
    if(!isOrdered(angle)){
        reorder(angle, lift);
    }
    
    cout << "Enter the flight-path angle: \n";
    cin >> userAngle;
    
    cout << interpolation(userAngle, angle, lift) << endl;
    
    cout << "Do you want to try another flight-path angle?\n";
    cin >> doAgain;
    
    while(doAgain == "Yes"){
        cout << "Enter the flight-path angle: \n";
        cin >> userAngle;
        
        cout << interpolation(userAngle, angle, lift) << endl;
        
        cout << "Do you want to try another flight-path angle?\n";
        cin >> doAgain;
    }
    
    return 0;
}

void readData(const string &inputFile, vector<double> &angle, vector<double> &lift){
    ifstream inFS;              //in file stream declaration
    inFS.open(inputFile);       //opening the inputFile as passed in to this function, received from the user
    double intake;              //gets the entire line for later processing
    
    //checking to see if the file opened correctly
    if(!inFS.is_open()){
        cout << "Error opening " << inputFile << endl;
        exit(1);
    }

     //replacement for eof statement, read in values in pairs of two to the different vectors
     while(inFS >> intake){
         angle.push_back(intake);
         inFS >> intake;
         lift.push_back(intake);
     }
}

double interpolation(double userAngle, const vector<double> &angle, const vector<double> &lift){
    for(unsigned int i = 0; i < angle.size(); i++){
        if(angle.at(i) == userAngle){
            return lift.at(i);
        }
    }
    for(unsigned int i = 0; i < angle.size(); i++){
        if(userAngle > angle.at(i)){
            return lift.at(i) + ((userAngle - angle.at(i)) / (angle.at(i + 1) - angle.at(i))) * (lift.at(i + 1) - lift.at(i));
        }
    }
    
    return 0;
    
//welllllll none of the stuff below worked even though it shouldve been equivalent to what's above :/
//     int tempLowerBound;
//     int tempUpperBound;
//     for(unsigned int i = 0; i < angle.size(); i++){
//         if(angle.at(i) == userAngle){
//             return lift.at(i);
//         }
//     }
    
//     for(unsigned int i = 1; i < angle.size(); i++){
//         if((angle.at(i - 1) < userAngle) && (angle.at(i) > userAngle)){
//             tempLowerBound = angle.at(i);
//             tempUpperBound = angle.at(i + 1);
//         }
//     }
//     return lift.at(tempLowerBound) + ((userAngle - tempLowerBound) / (tempUpperBound - tempLowerBound)) * (lift.at(tempUpperBound) - lift.at(tempLowerBound));
}


bool isOrdered(const vector<double> &angle){
    for(unsigned int i = 0; i + 1 < angle.size(); i++){
        if(angle.at(i) > angle.at(i + 1)){
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &angle, vector<double> &lift){
    int min;
    for(unsigned int i = 0; i < angle.size(); i++){
        for(unsigned int j = i + 1; j < angle.size(); j++){
            if(angle.at(i) > angle.at(j)){
                min = j;
                swap(angle.at(i), angle.at(min));
                swap(lift.at(i), lift.at(min));
            }
        }
    }
}
