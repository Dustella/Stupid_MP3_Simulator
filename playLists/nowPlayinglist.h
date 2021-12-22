#ifndef NOWPLAYINGLIST
#define NOWPLAYINGLIST

#include "playList.cpp"

class nowPlayinglist: public playlist
{
private:

    int nowPlayingID;

public:
    nowPlayinglist();
    nowPlayinglist(playlist M);

    int getNowPlayingID()  ;
    void setNowPlayingID(int nowPlayingID);
    music getNowPlayingMusic() ;
    void insertNextPlaying(music newPlaying);

};

#endif