#include "nowPlayinglist.h"

int nowPlayinglist::getNowPlayingID() const { return nowPlayinglist::nowPlayingID; }

void nowPlayinglist::setNowPlayingID(int nowPlayingID) { this->nowPlayingID = nowPlayingID; }

music nowPlayinglist::getNowPlayingMusic()const { return nowPlayinglist::nowPlayingMusic; }