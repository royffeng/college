#include <bits / stdc++.h>
#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength){
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;

    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* node) {
    PlaylistNode* temp = nextNodePtr;
    nextNodePtr = node;
    node->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* node) {
    nextNodePtr = node;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() : head(nullptr), tail(nullptr) {}

void Playlist::print(string title) const {
    cout << title << " - OUTPUT FULL PLAYLIST\n";
    if(empty()) {
        cout << "Playlist is empty\n";
    }else {
        int counter = 1;
        PlaylistNode* node = head;
        while (node) {
            cout << counter << ".\n";
            node->PrintPlaylistNode();

            counter++;
            node = node->GetNext();
        }
    }
}

bool Playlist::empty() const {
    return head == nullptr;
}

void Playlist::push_back(PlaylistNode* node) {
    if(empty()) {
        head = node;
        tail = node;
    }else {
        tail->SetNext(node);
        tail = node;
    }
}

PlaylistNode* Playlist::remove(string id) {
    PlaylistNode* prevPointer = nullptr;
    PlaylistNode* currPointer = head;

    while (currPointer && currPointer->GetID() != id) {
        prevPointer = currPointer;
        currPointer = currPointer->GetNext();
    }

    if(currPointer) {
        if (prevPointer) {
            prevPointer->SetNext(currPointer->GetNext());
        }
        else {
            head = currPointer->GetNext();
        }

        if (!currPointer->GetNext()) {
            tail = prevPointer;
        }

        return currPointer;
    }else {
        return nullptr;
    }
}

void Playlist::changePos(int initialPos, int newPos) {
    int initialIndex = 1;
    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;

    if(initialPos < 1) {
        cout << "Invalid current position.\n";
        return;
    }

    //Find the songPosition
    while(initialIndex < initialPos) {
        if(curr) {
            prev = curr;
            curr = curr->GetNext();
            initialIndex++;

            if(!curr) {
                cout << "Invalid current position.\n";
                return;
            }
        }else {
            cout << "Invalid current position.\n";
            return;
        }
    }

    if(prev) {
        prev->SetNext(curr->GetNext());
    }else {
        head = curr->GetNext();
    }

    if (curr == tail) {
        tail = prev;
    }

    if(newPos <= 1) {
        if (empty()) {
            tail = curr;
        }

        curr->SetNext(head);
        head = curr;
        cout << '"' << curr->GetSongName() << '"' << " moved to position 1\n";
    }
    else // Node is inserted after the head
    {
        if (empty()) // The list is empty after removing the node
        {
            push_back(curr);
            cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl;
        }
        else
        {
            int newPosIndex = 2;
            PlaylistNode* prevNode = head;
            PlaylistNode* afterNode = head->GetNext();
            while (newPosIndex < newPos && afterNode)
            {
                prevNode = afterNode;
                afterNode = afterNode->GetNext();
                newPosIndex++;
            }

            prevNode->InsertAfter(curr);

            if (!afterNode) // the node is being inserted at the tail
            {
                tail = curr;
            }
            cout << '"' << curr->GetSongName() << '"' << " moved to position " << newPosIndex << endl;
        }
    }
}

void Playlist::printByArtist(string artist) const
{
    int positionCounter = 1;
    PlaylistNode* node = head;
    while (node)
    {
        if (node->GetArtistName() == artist)
        {
            cout << positionCounter << "." << endl;
            node->PrintPlaylistNode();
            cout << endl;
        }

        positionCounter++;
        node = node->GetNext();
    }
}

int Playlist::totalTimeSeconds() const
{
    int total = 0;
    PlaylistNode* node = head;
    while (node)
    {
        total += node->GetSongLength();
        node = node->GetNext();
    }
    return total;
}
