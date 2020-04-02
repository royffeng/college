#include <bits/stdc++.h>
#include "Playlist.h"

using namespace std;

//The following code was largely received from LePendu in the slack workspace

void PrintMenu(const string playlistTitle) {
   char menuOp = ' ';
   string uniqueID;
   string songName;
   string artistName;
   int songLength = 0;
   int numNodes = 0;
   int songPosition = 0;
   int newPosition = 0;
   int totalTime;
   PlaylistNode* newSong = 0;
   PlaylistNode* currNode = 0;
   PlaylistNode* songNode = 0;
   PlaylistNode* prevNode = 0;
   PlaylistNode* insertPosNode = 0;
   PlaylistNode* headNode = 0;
   PlaylistNode* tailNode = 0;
   PlaylistNode* currPrintNode = 0;
   // Output menu option, prompt users for valid selection
   while(menuOp != 'q') {
      menuOp = ' ';
      cout << playlistTitle << " PLAYLIST MENU" << endl;
      cout << "a - Add song" << endl;
      cout << "d - Remove song" << endl;
      cout << "c - Change position of song" << endl;
      cout << "s - Output songs by specific artist" << endl;
      cout << "t - Output total time of playlist (in seconds)" << endl;
      cout << "o - Output full playlist" << endl;
      cout << "q - Quit" << endl << endl;
      while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
             menuOp != 's' && menuOp != 't' && menuOp != 'o' && menuOp != 'q') {
         cout << "Choose an option:" << endl;
         cin >> menuOp;
      }
      // Call corresponding menu action
	  if(menuChoice == 'a') {
		  cout << "ADD SONG\n";
		  cout << "Enter song's unique ID:\n";
		  cin >> uniqueID;
		  cout << "Enter song's name:\n";
		  cin >> songName;
		  cout << "Enter artist's name:\n";
		  cin >> artistName;
		  cout << "Enter song's length (in seconds):\n";
		  cin >> songLength;
		  list.addSong(uniqueID, songName, artistName, songLength);

	  }else if(menuChoice == 'b') {
		  cout << "REMOVE SONG" << endl << "Enter song's unique ID:\n";
		  cin >> uniqueID;
		  list.removeSong(uniqueID);

	  }else if(menuChoice == 'c') {
		  cout << "CHANGE POSITION OF SONG\n" << "Enter song's current position:\n";
		  cin >> songPosition;
		  cout << "Enter new position for song:\n";
		  cin >> newPosition;
		  list.changePosition(songPosition, newPosition);

	  }else if(menuChoice == 'o') {
		  list.outputFullPlaylist();

	  }else if(menuChoice == 's') {
		  cout << "OUTPUT SONGS BY SPECIFIC ARTIST\n" << "Enter artist's name:\n";
		  cin >> artistName;
		  list.specificArtist(artistName);

	  }else if(menuChoice == 't') {
		  cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n" << "Total time: " << list.totalTime() << " seconds";
	  }
}

int main() {
   string playlistTitle;
   // Prompt user for playlist title
   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   cout << endl;
   // Output play list menu options
   PrintMenu(playlistTitle);
   return 0;
}
