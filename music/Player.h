#ifndef PLAYER_H
#define PLAYER_H

#include "../playLists/nowPlayinglist.h"

using namespace std;

class Player
{
public:
	void setPlaybackState(string mode);
	void play();
	void pause();
	void nextPlay();
	void previousPlay();

	string playingInfo();

	Player(playlist M);
	Player();

	void setPlaylist(playlist L);

private:
	bool isPaused = true;
	string playbackState = "loop";
	nowPlayinglist nowPlaying;
};

#endif
