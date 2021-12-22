#ifndef NOWPLAYINGLIST
#define NOWPLAYINGLIST

#include "playList.h"

class nowPlayinglist: public playlist
{
private:

    int nowPlayingID;
    music nowPlayingMusic;

public:
    nowPlayinglist(playlist M);

    int getNowPlayingID() const ;
    void setNowPlayingID(int nowPlayingID);
    music getNowPlayingMusic() const;
    void insertNextPlaying(music newPlaying);

};

#endif