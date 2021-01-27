#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"

// default constructor
PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string artistNameN, string songNameN, string uniqueIDn, int songLengthN) {
    this->artistName = artistNameN;
    this->songName = songNameN;
    this->uniqueID = uniqueIDn;
    this->songLength = songLengthN;
    nextNodePtr = nullptr;
}

// inserts song after        
void PlaylistNode::InsertAfter(PlaylistNode* node1) {
    PlaylistNode* temp = nullptr;
    temp = nextNodePtr;
    nextNodePtr = node1;
    node1->SetNext (temp);
}

void PlaylistNode::SetNext(PlaylistNode* node2) {
    nextNodePtr = node2;
}

string PlaylistNode::GetID(){
    return GetID();
}

string PlaylistNode::GetSongName() {
    return GetSongName();
}

string PlaylistNode::GetArtistName() {
    return GetArtistName();
}

int PlaylistNode::GetSongLength() {
    return GetSongLength();
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    // cout output from example in prompt
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds) : " << songLength << endl;
}

