#include <iostream>
#include <iomanip>
#include "Playlist.h"

using namespace std;

//The following code was largely received from LePendu in the slack workspace

void PrintMenu(const string playlistTitle) {
    char menu = ' ';
    string uniqueID = "";
    string songName = "";
    string artistName = "";
    int songLength = 0;
    int currPos = 0;
    int newPos = 0;
    int numIter = 0;
    int max = 0;
    PlaylistNode* playlist = nullptr;
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    PlaylistNode* temp = nullptr;
    PlaylistNode* curr = nullptr;

    while(menu != 'q') {
        menu = ' ';
        while(!(menu == 'a' || menu == 'd' || menu == 'c' || menu == 's' || menu == 't' || menu == 'o' || menu == 'q')) {
            cout << playlistTitle << " PLAYLIST MENU" << endl
                << "a - Add song" << endl
                << "d - Remove song" << endl
                << "c - Change position of song" << endl
                << "s - Output songs by specific artist" << endl
                << "t - Output total time of playlist (in seconds)" << endl
                << "o - Output full playlist" << endl
                << "q - Quit" << endl << endl
                << "Choose an menu:";
            cin >> menu;
            cout << endl;
            cin.ignore(1);
        }

        if(menu == 'a') {
            cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);

            cout << "Enter song's name:" << endl;
            getline(cin, songName);

            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;

            curr = new PlaylistNode(uniqueID, songName, artistName, songLength);

            if(head == nullptr) {
                head = curr;
                tail = curr;
            }else {
                temp = tail;
                tail = curr;
                temp->SetNext(curr);
            }
        }else if(menu == 'd') {
            cout << "REMOVE SONG" << endl << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);

            curr = head;
            temp = curr;

            while(curr != nullptr) {
                if(curr->GetID() == uniqueID) {
                    songName = curr->GetSongName();
                    if(head == curr) {
                        if(head == tail) {
                            tail = nullptr;
                        }
                        temp = head;
                        head = curr->GetNext();
                        delete temp;
                        curr = head;
                        temp = curr;
                    }else {
                        if(tail == curr) {
                            tail = temp;
                        }

                        temp->SetNext(curr->GetNext());
                        delete curr;
                        curr = temp;
                        curr = curr->GetNext();

                    }
                    cout << "\"" << songName << "\" removed." << endl << endl;
                }else {
                    temp = curr;
                    curr = curr->GetNext();
                }
            }
        }else if(menu == 'c') {
            cout << "CHANGE POSITION OF SONG" << endl << "Enter song's current position:" << endl;
            cin >> currPos;

            cout << "Enter new position for song:" << endl;
            cin >> newPos;

            curr = head;
            temp = head;
            max = currPos;

            numIter = 1;

            while(numIter < currPos) {
                temp = curr;
                curr = curr->GetNext();
                ++numIter;
            }

            songName = curr->GetSongName();

            if(head == curr) {
                head = curr->GetNext();
            }else if(tail == curr) {
                temp->SetNext(tail->GetNext());
                tail = temp;
            }else {
                temp->SetNext(curr->GetNext());
            }

            temp = head;
            numIter = 2;

            while(numIter < newPos) {
                temp = temp->GetNext();
                ++numIter;
            }

            if(newPos <= 1) {
                curr->SetNext(head);
                head = curr;
            }else if(newPos > (max - 1)) {
                tail = curr;
                temp->InsertAfter(curr);
            }else {
                temp->InsertAfter(curr);
            }
            cout << "\"" << songName << "\" moved to position " << newPos << endl << endl;
        }else if(menu == 's') {
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl << "Enter artist's name:" << endl;
            getline(cin, artistName);

            curr = head;
            numIter = 1;

            while(curr != nullptr) {
                if(curr->GetArtistName() == artistName) {
                    cout << numIter << "." << endl;
                    playlist->PrintPlaylistNode();
                }
                curr = curr->GetNext();
                numIter++;
            }
        }else if(menu == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl << "Total time: ";

            curr = head;
            songLength = 0;

            while(curr != nullptr) {
                songLength += curr->GetSongLength();
                curr = curr->GetNext();
            }

            cout << songLength << " seconds" << endl;
        }else if(menu == 'o') {
            curr = head;
            numIter = 0;

            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

            if(head == nullptr) {
                cout << "Playlist is empty" << endl << endl;
            }else {
                while(curr != nullptr) {
                    numIter++;
                    cout << numIter << "." << endl;
                    playlist->PrintPlaylistNode();
                    curr = curr->GetNext();
                }
            }
        }
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
