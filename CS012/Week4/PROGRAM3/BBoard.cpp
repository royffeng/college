#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "Message.h"
#include "User.h"
#include "BBoard.h"

BBoard::BBoard(){
    title = "";
    userList = userList;
    currentUser = User();
    messageList = messageList;
}

BBoard::BBoard(const string &t){
    title = t;
    userList = userList;
    currentUser = User();
    messageList = messageList;
}

bool BBoard::loadUsers(const string &input){
    string user;
    string pass;
    ifstream inFS;
    inFS.open(input);
    if (!inFS.is_open()) {
        return false;
    }
    while (user != "end"){
        inFS >> user;
        inFS >> pass;
        userList.push_back(User(user,pass));
    }
    inFS.close();
 return true;
}

bool BBoard::login(){
     /* Asks for and validates a user/password.
     * Always asks for both user and password combo unless 'q' or 'Q' entered.
     * Checks userList to validate user and password.
     * If valid, sets currentUser to this User, outputs welcome message, 
     * then returns true.
     * Otherwise outputs error message and then repeats request
     * for username/password.
     * Continues until valid user/password 
     * or until 'q' or 'Q' is entered for username.
     * If 'q' or 'Q' is entered, does not ask for password, outputs "Bye!"
     * and then returns false.
     */
    cout << "Welcome to " << title << endl;
    string user;
    string pass;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> user;
    if ((user == "q") || (user== "Q")){
        cout << endl;
        cout << "Bye!" << endl;
        return false;
    }
    while ((user != "q") || (user!= "Q")){
         cout << endl << "Enter your password: ";
         cin >> pass;
         cout << endl;
         bool check = false;
         for (unsigned int i = 0; i < userList.size(); ++i){
            
            if  (userList.at(i).check(user, pass) == true){
                currentUser = userList.at(i);
                cout << "Welcome back " << user << "!" << endl;
                cout << endl;
                check = true;
                return true;
            }
    }
        if (check == false){
            cout << "Invalid Username or Password!" << endl;
            cout << endl;
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> user;
            if ((user == "q") || (user== "Q")){
                cout << endl;
                cout << "Bye!" << endl;
                return false;
        }
    }
} 
        return false;

}

void BBoard::run(){
        /* Contains main loop of Bulletin Board.
     * First verifies a User has been logged in before calling this function.
     * (Do not call login function within this function.)
     * Returns from **function** immediately if no User logged in (Default User).
     * Continues to display menu options to user and performs requested action
     * until user chooses to quit.
     * See output samples for exact format of menu.
     */
//    User check = currentUser;
//    User d = User();
//    userExists()
   char in = ' ';
   while ((in != 'q') || (in != 'q')){
       cout << "Menu" << endl;
       cout << "- Display Messages ('D' or 'd')" << endl;
       cout << "- Add New Message ('N' or 'n')" << endl;
       cout << "- Quit ('Q' or 'q')" << endl;
       cout << "Choose an action: ";
       cin >> in;
       if ((in == 'D') || (in == 'd')){
           cout << endl;
           display();
       }
       if ((in == 'N') || (in == 'n')){
           cout << endl;
           addMessage();
       }
       if ((in == 'Q') || (in == 'q')){
           cout << endl;
           cout << "Bye!" << endl;
           break;
       }
   }
}

void BBoard::display() const{
    bool atZero = false;
    if (messageList.size() == 0){
        cout << "Nothing to Display." << endl;
        cout << endl;
        atZero = true;
    }
    if (!atZero){
        for (unsigned int i = 0; i < messageList.size(); ++i){   
            cout << "---------------------------------------------------------" << endl;
            cout << "Message #" << i + 1 << ": ";
            messageList.at(i).display();
            cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    }

}

void BBoard::addMessage(){
    string author = currentUser.getUsername();
    string subject;
    string body;
    cin.ignore(256, '\n');
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << endl;
    cout << "Enter Body: ";
    getline(cin, body);
    cout << endl;
    cout << "Message Recorded!" << endl;
    cout << endl;
    messageList.push_back(Message(author, subject, body));
}
