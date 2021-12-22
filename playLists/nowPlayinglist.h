#ifndef NOWPLAYINGLIST
#define NOWPLAYINGLIST

#include "playList.h"

class nowPlayinglist
{
private:

    int nowPlayingID;
    music nowPlayingMusic;
    
public:

    int getNowPlayingID() const ;
    void setNowPlayingID(int nowPlayingID);
    music getNowPlayingMusic() const;
    void insertNextPlaying(music newPlaying);

};

#endif