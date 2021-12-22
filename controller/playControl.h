#ifndef play_control
#define play_control

#include "../music/Player.h"

class playControl
{
private:
    Player player;
public:
    string nowPlaying();
    string nowPlayingList();

    

    playControl();
    ~playControl();
};




#endif