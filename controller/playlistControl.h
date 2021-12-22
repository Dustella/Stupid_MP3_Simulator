#ifndef playlist_control
#define playlist_control

#include "../store/store.cpp"

class playlistControl
{
private:
    vector<playlist> allLists;
    nowPlayinglist nowPlaying;
    store storage;

public:
    void init();
    void promotListOpt();
    void promotAddGuide();
    void addMusic(playlist &ls);
    playlistControl();
    ~playlistControl();
};

#endif