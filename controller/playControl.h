#ifndef play_control
#define play_control

#include "../music/Player.h"
#include "playlistControl.h"
#include "../store/store.h"

class playControl
{
private:

    store storage;
    Player player;
    playlistControl lsctl;

public:
    
    void welcome();

    void setNowPlayingList();

    string nowPlaying();
    string nowPlayingList();

    

    playControl();
    ~playControl();
};




#endif