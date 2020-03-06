#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);


int main() {
   vector<int> jerseyNum;
   vector<int> playerRating;
   int ingest;
   char userSelect;

   //inputting player information
   for(int i = 0; i < 5; i++){
      cout << "Enter player "<< i + 1 << "'s jersey number:\n";
      cin >> ingest;
      jerseyNum.push_back(ingest);
      cout << "Enter player " << i + 1 << "'s rating:\n";
      cin >> ingest;
      playerRating.push_back(ingest);
      
      cout << endl;
   }
   
   //outputting the roster
   /*cout << "ROSTER\n";
   for(unsigned int i = 0; i < jerseyNum.size(); i++){
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i)
      << ", Rating: " << playerRating.at(i) << endl;
   }
   cout << endl;
   */
   outputRoster(jerseyNum, playerRating);
   
   cout << "\nMENU\n";
   cout << "a - Add player\n";
   cout << "d - Remove player\n";
   cout << "u - Update player rating\n";
   cout << "r - Output players above a rating\n";
   cout << "o - Output roster\n";
   cout << "q - Quit\n\n";
   cout << "Choose an option:\n";
   
   cin >> userSelect;
   
   if(userSelect == 'a'){
      addPlayer(jerseyNum, playerRating);
   }
   if(userSelect == 'd'){
      removePlayer(jerseyNum, playerRating);
   }
   if(userSelect == 'u'){
      updatePlayerRating(jerseyNum, playerRating);
   }
   if(userSelect == 'r'){
      outputPlayersAboveRating(jerseyNum, playerRating);
   }
   if(userSelect == 'o'){
      outputRoster(jerseyNum, playerRating);
   }
   while(userSelect != 'q'){
      cout << "\nMENU\n";
      cout << "a - Add player\n";
      cout << "d - Remove player\n";
      cout << "u - Update player rating\n";
      cout << "r - Output players above a rating\n";
      cout << "o - Output roster\n";
      cout << "q - Quit\n\n";
      cout << "Choose an option:\n";
      
      cin >> userSelect;
   
      if(userSelect == 'a'){
         addPlayer(jerseyNum, playerRating);
      }
      if(userSelect == 'd'){
         removePlayer(jerseyNum, playerRating);
      }
      if(userSelect == 'u'){
         updatePlayerRating(jerseyNum, playerRating);
      }
      if(userSelect == 'r'){
         outputPlayersAboveRating(jerseyNum, playerRating);
      }
      if(userSelect == 'o'){
         outputRoster(jerseyNum, playerRating);
      }
   }

   return 0;
}

void outputRoster(const vector<int> &jerseyNum, const vector<int> &playerRating){
   cout << "ROSTER\n";
   for(unsigned int i = 0; i < jerseyNum.size(); i++){
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i)
      << ", Rating: " << playerRating.at(i) << endl;
   }
}

void addPlayer(vector<int> &jerseyNum, vector<int> &playerRating){
   int ingest;
   
   cout << "Enter another player's jersey number:\n";
   cin >> ingest;
   jerseyNum.push_back(ingest);
   cout << "Enter another player's rating:";
   cin >> ingest;
   playerRating.push_back(ingest);
   
   cout << endl;
}

void removePlayer(vector<int> &jerseyNum, vector<int> &playerRating){
   int userDelete;
   
   cout << "Enter a jersey number:\n";
   cin >> userDelete;
   
   for(unsigned int i = 0; i < jerseyNum.size(); i++){
      if(jerseyNum.at(i) == userDelete){
         jerseyNum.erase(jerseyNum.begin() + i);
         playerRating.erase(playerRating.begin() + i);
      }
   }
}


void updatePlayerRating(const vector<int> &jerseyNum, vector<int> &playerRating){
   int userUpdate;
   int updateValue;
   
   cout << "Enter a jersey number:\n";
   cin >> userUpdate;
   cout << "Enter a new rating for player:\n";
   cin >> updateValue;
   
   for(unsigned int i = 0; i < jerseyNum.size(); i++){
      if(jerseyNum.at(i) == userUpdate){
         playerRating.at(i) = updateValue;
      }
   }
}

void outputPlayersAboveRating(const vector<int> &jerseyNum, const vector<int> &playerRating){
   int minRating;
   
   cout << "Enter a rating:\n";
   cin >> minRating;
   cout << "\nABOVE " << minRating << endl;
   
   for(unsigned int i = 0; i < jerseyNum.size(); i++){
      if(playerRating.at(i) > minRating){
         cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << playerRating.at(i) << endl;
      }
   }
}
