#ifndef storee
#define storee

#include <iostream>
#include <fstream>
#include "../playLists/nowPlayinglist.cpp"
#include "../utils/CJsonObject.cpp"

using namespace std;
using namespace neb;

class store
{
private:
public:
    CJsonObject data;
    store();
    ~store();
    void addPlaylist(playlist ls);
    void syncPlaylist(playlist ls);
    void deletePlaylist(playlist ls);

    string fetchStore();
    void writeStore();

    vector<playlist> getAllPlaylists();
    playlist getPlaylist(string name);
};

#endif