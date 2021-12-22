#ifndef PLAYER_H
#define PLAYER_H

#include "music.h"
#include "playList.h"
#include "nowPlayinglist.h"

using namespace std;

class Player
{
public:
	void setPlaybackState(string mode);
	void play();
	void pause();
	void nextPlay();
	void previousPlay();

	Player(playlist M);
	Player();

private:
	bool isPaused = true;
	string playbackState = "loop";
	nowPlayinglist nowPlaying;
};

#endif
