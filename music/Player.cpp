#include "Player.h"
#include "playList.h"
#include "favMusicList.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void Player::setPlaybackState(string mode)
{
	this->playbackState = mode;
}

void Player::play()
{
	this->isPaused = false;
}

void Player::pause()
{
	this->isPaused = true;
}

void Player::nextPlay()
{
	nowPlaying.setNowPlayingID(nowPlaying.getNowPlayingID() + 1);
}

void Player::previousPlay()
{
	nowPlaying.setNowPlayingID(nowPlaying.getNowPlayingID() - 1);
}


Player::Player(playlist M) : nowPlaying(M)
{
}
