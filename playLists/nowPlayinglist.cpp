#include "nowPlayinglist.h"

int nowPlayinglist::getNowPlayingID() 
{
    return nowPlayinglist::nowPlayingID;
}

void nowPlayinglist::setNowPlayingID(int nowPlayingID)
{
    this->nowPlayingID = nowPlayingID;
}

music nowPlayinglist::getNowPlayingMusic() 
{
    return musiclist[getNowPlayingID()];
}




void nowPlayinglist::insertNextPlaying(music newPlaying)
{
    insert(nowPlayingID, newPlaying);
}

nowPlayinglist::nowPlayinglist(playlist M) : playlist(M)
{
    this->nowPlayingID = 0;
}
nowPlayinglist::nowPlayinglist() : playlist()
{
    this->nowPlayingID = 0;
}