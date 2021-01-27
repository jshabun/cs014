#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"

void PrintMenu (string PlaylistTitle);

int main () {
    string playlistTitle;
    // char menuOptions;

    cout << "Enter playlist's title:" << endl;

    // cin >> playlistTitle;
    getline (cin, playlistTitle); // input playlist name (getline because it can be more than one word)
    cout << endl;

    // menu options
    PrintMenu(playlistTitle);

    return 0;
}

void PrintMenu(/*char menuOption,*/ string playlistTitle) {
    // variables
    char menuOption = ' ';
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
            
    // initializing head and tail to nullptr due to empty node 
    // and to be able to link to other nodes that will be added and removed    
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;

    PlaylistNode* temp = nullptr;
    PlaylistNode* curr = nullptr;
    
    // cout << playlistTitle << " PLAYLIST MENU" << endl;
    // cout << "a - Add song" << endl;
    // cout << "d - Remove song" << endl;
    // cout << "c - Change position of song" <<  endl;
    // cout << "s - Output songs by specific artist" << endl;
    // cout << "t - Output total time of playlist (in seconds)" << endl;
    // cout << "o - Output full playlist" << endl;
    // cout << "q - Quit" << endl;
    // cout << endl << "Choose an option:" << endl;

    // cin >> menuOption;

    // menu options
    while (menuOption != 'q') {
        menuOption = ' ';

        while (!(menuOption == 'a' || menuOption == 'd' || menuOption == 'c' || menuOption == 's' || menuOption == 't' || menuOption == 'o' || menuOption == 'q')) {
            cout << playlistTitle << " PLAYLIST MENU" << endl;
            cout << "a - Add song" << endl;
            cout << "d - Remove song" << endl;
            cout << "c - Change position of song" <<  endl;
            cout << "s - Output songs by specific artist" << endl;
            cout << "t - Output total time of playlist (in seconds)" << endl;
            cout << "o - Output full playlist" << endl;
            cout << "q - Quit" << endl;
            cout << endl << "Choose an option:";

            cin >> menuOption;
            cout <<  endl;
        }
        // add song
        if (menuOption == 'a') {
            // Add song
            // displays and prompts
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID: " << endl;
            cin >> uniqueID;
            cout << endl;
            
            cout << "Enter song's name: " << endl;
            getline (cin, songName);
            cout << endl;

            cout << "Enter artist's name: " << endl;
            getline (cin, artistName);
            cout << endl;

            cout << "Enter song's length (in seconds): ";
            cin >> songLength;
            cout << endl;

            // background linking and nodes
            PlaylistNode* addSong = new PlaylistNode(uniqueID, songName, artistName, songLength); // creating a new node to add song 
            if (head == nullptr) {
                head = addSong;
                tail = head;
            } else {
                temp = tail;
                tail = addSong;
                temp->SetNext(addSong);
            }


        } else if (menuOption == 'd') {
            // remove song
            string uniqueID;
            string songName;

            cout << "REMOVE SONG" << endl;
            cout << "Enter song's Unique ID:" << endl;
            cin >> uniqueID;
            cout << endl;

            curr = head;
            temp = nullptr;

            while (curr != nullptr) 
            {
                if (curr->GetID() == uniqueID) 
                {
                    if (curr == head) 
                    {
                        cout << "\"" << curr->GetSongName() << "\" removed" << endl;
                        head = curr->GetNext();
                        delete curr;
                    } 
                    else 
                    {
                        PlaylistNode* temp2 = curr->GetNext();
                        temp->SetNext(temp2);
                        cout << "\"" << curr->GetSongName() << "\" removed" << endl;
                        delete temp2;
                    }
                }
                temp = curr;
                curr = curr->GetNext();
            }

            // cout << "\"" << songName << "\" removed" << endl;


        } else if (menuOption == 'c') {
            // change position of song
            int songPosition;
            int newSongPos;

            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's new position:" << endl;
            cin >> songPosition;
            cout << endl;
            cout << "Enter new position for song:" << endl;
            cin >> newSongPos;

            curr = head;
            temp = head;

            //PlaylistNode
            
            cout << "\"" << "\" moved to position " << newSongPos << endl;

        } else if (menuOption == 's') {
            // output songs by specific artist
            string artistName;
            int i = 1;
            
            cout << "OUPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << endl << endl;

            curr = head;
            while (curr != nullptr) {
                if (curr->GetArtistName() == artistName) {
                    cout << i << '.' << endl;
                    curr->PrintPlaylistNode();
                }

                curr = curr->GetNext();
                i++;
            }

            // cout << "Unique ID: " << uniqueID << endl;
            // cout << "Song Name: " << songName << endl;
            // cout << "Artist Name: " << artistName << endl;
            // cout << "Song Length (in seconds): " << songLength << endl;


        } else if (menuOption == 't') {
            int totalTime = 0;
            temp = head;
            while (temp) {
                totalTime = totalTime + temp->GetSongLength();
                temp = temp->GetNext();
            }
            
            // output total time of playlist (in seconds)
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << totalTime << " seconds" << endl;

        } else if (menuOption == 'o') {
            int i  = 1; // for  counting nodes to display

            // output full playlist
            cout << playlistTitle <<  " - OUTPUT FULL PLAYLIST" << endl;

            if (head == nullptr || head == 0) {
                // check whether playlist is empty
                // by checking if head points to something
                cout << "Playlist is empty" << endl << endl;
            } else {
                curr = head;
                while (curr != nullptr) {
                    cout << i << '.' << endl;
                    curr->PrintPlaylistNode();
                    curr = curr->GetNext();
                    ++i;
                }
            }

        }
    }
    
    /* if (menuOption == 'a' || 'd' || 'c' || 's' || 't' || 'o' || 'q') {
        return menuOption;
    } else {
        cout << playlistTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" <<  endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl << "Choose an option: ";

        cin >> menuOption;
    } */
}