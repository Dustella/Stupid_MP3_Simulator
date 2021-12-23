#include "playControl.h"
#include "playlistControl.cpp"
#include "../music/Player.cpp"
#include "../store/store.cpp"
#include <string>

playControl::playControl() : player()
{
    player.setPlaylist(storage.getPlaylist("nowPlayinglist"));
    welcome();
}

playControl::~playControl() {}

string playControl::nowPlaying()
{
    string result;
    result += "================================";
    result += "";
    return result;
}

void playControl::setNowPlayingList()
{
    system("clear");
    cout << "Choose a list to replace" << endl;
    lsctl.printAllLists();
    int a;
    cin >> a;
    player.setPlaylist(lsctl.allLists[a]);
}

void playControl::welcome()
{
    system("clear");
    cout << "Welcome to use player simulator" << endl;
    cout << player.playingInfo() << endl;
    cout << "1. Manage All Playlists" << endl;
    cout << "2. Pause" << endl;
    cout << "3. Resume" << endl;
    cout << "4. Next" << endl;
    cout << "5. Prev" << endl;
    cout << "6. SetPlaylist" << endl;
    cout << "7. Quit" << endl;
    cout << "================================" << endl;
    int ins;
    cin >> ins;
    switch (ins)
    {
    case 1:
    {
        lsctl.promotListOpt();
        welcome();
        break;
    }
    case 2:
    {
        player.pause();
        welcome();
        break;
    }
    case 3:
    {
        player.play();
        welcome();
        break;
    }
    case 4:
    {
        player.nextPlay();
        welcome();
        break;
    }
    case 5:
    {
        player.previousPlay();
        welcome();
        break;
    }
    case 6:
    {
        setNowPlayingList();
        welcome();
        break;
    }
    case 7:
    {
        return;
    }
    default:
    {
        system("clear");
        cout << "error" << endl;
        welcome();
        break;
    }
    }
}

