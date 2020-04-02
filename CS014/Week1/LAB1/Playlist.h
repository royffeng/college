//This entire header file was coded by LePendu, provided through the slack workspace

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
using namespace std;
class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string initID, ... HIDDEN..., PlaylistNode* nextLoc = 0);
    void InsertAfter(... HIDDEN...);
    void SetNext(PlaylistNode* nodePtr);
    ... HIDDEN...
        string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};
#endif
