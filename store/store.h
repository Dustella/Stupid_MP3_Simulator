#ifndef storee
#define storee

#include <iostream>
#include <fstream>
#include "../playLists/playList.h"
#include "../utils/CJsonObject.hpp"

using namespace std;
using namespace neb;

class store
{
public:
    store();
    void addPlaylist(string name);
    void syncPlaylist(playlist ls);
    void deletePlaylist(playlist ls);

    string fetchStore();
    void writeStore(string content);

    vector<playlist> getAllPlaylists();
    playlist getPlaylist(string name);
private:
    CJsonObject data;
};

#endif