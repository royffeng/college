#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    
    vector<int> nums;
    string inputFile;
    string outputFile;
    int temp;
    int valAvg;
    
    // Assign to inputFile value of 2nd command line argument
    inputFile = argv[1];
    // Assign to outputFile value of 3rd command line argument
    outputFile = argv[2];
    // Create input stream and open input csv file.
    ifstream inFS;
    inFS.open(inputFile);
    // Verify file opened correctly.
    // Output error message and return 1 if file stream did not open correctly.
    if(!inFS.is_open()){
        cout << "Error opening " << inputFile << endl;
        return 1;
    }
    // Read in integers from input file to vector.
    while(inFS >> temp){
        inFS.ignore(256, ',');
        nums.push_back(temp);
    }
    // Close input stream.
    inFS.close();
    // Get integer average of all values read in.
    temp = 0;
    for(unsigned int i = 0; i < nums.size(); i++){
        temp += nums.at(i);
    }
    valAvg = temp / nums.size();
    // Convert each value within vector to be the difference between the original value and the average.
    for(unsigned int i = 0; i < nums.size(); i++){
        nums.at(i) -= valAvg;
    }
    // Create output stream and open/create output csv file.
    ofstream opFS;
    opFS.open(outputFile);
    // Verify file opened or was created correctly.
    // Output error message and return 1 if file stream did not open correctly.
    if(!opFS.is_open()){
        cout << "Error opening " << outputFile << endl;
        return 1;
    }
    // Write converted values into ouptut csv file, each integer separated by a comma.
    for(unsigned int i = 0; i < nums.size() - 1; i++){
        opFS << nums.at(i) << ",";
    }
    opFS << nums.at(nums.size() - 1);
    // Close output stream.
    opFS.close();
    
    return 0;
}
