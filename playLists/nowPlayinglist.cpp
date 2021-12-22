#include "nowPlayinglist.h"

int nowPlayinglist::getNowPlayingID() const { return nowPlayinglist::nowPlayingID; }

void nowPlayinglist::setNowPlayingID(int nowPlayingID) { this->nowPlayingID = nowPlayingID; }

music nowPlayinglist::getNowPlayingMusic() const { return nowPlayinglist::nowPlayingMusic; }

void nowPlayinglist::insertNextPlaying(music newPlaying)
{
    musicList::musiclist.insert(nowPlayingID, newPlaying);
}