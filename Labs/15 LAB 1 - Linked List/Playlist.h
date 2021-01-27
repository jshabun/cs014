#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode(); // default constructor
        PlaylistNode(string artistName, string songName, string uniqueID, int songLength); // parameterized constructor
        
        // public member functions
        void InsertAfter(PlaylistNode* node1);
        void SetNext(PlaylistNode* node2); // mutator
        
        string GetID(); // accessor
        string GetSongName(); // accessor
        string GetArtistName(); //accessor

        int GetSongLength(); // accessor
        
        PlaylistNode* GetNext(); // accessor
        
        void PrintPlaylistNode(); 

    private:
        // private data members
        string uniqueID; // initialized to "none" in default constructor
        string songName; // initialized to "none" in default constructor
        string artistName; // initialized to "none" in default constructor
        int songLength; // initialized to 0 in default constructor
        PlaylistNode* nextNodePtr; // initialized to 0 in default constructor


}; 

// 

#endif