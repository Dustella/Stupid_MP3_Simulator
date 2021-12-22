#include "Player.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

Player::Player() {}

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

void Player::setPlaylist(playlist ls)
{
	nowPlaying.setPlaylist(ls);
}

string Player::playingInfo()
{
	string info;
	info += "================================\n";
	info += "Title:";
	info += nowPlaying.getNowPlayingMusic().getTitle();
	info += "\nArtist:";
	info += nowPlaying.getNowPlayingMusic().getAuthor();
	info += "\nAlbum: ";
	info += nowPlaying.getNowPlayingMusic().getAlbum();
	if (isPaused)
	{
		info += "\n isPaused";
	}
	else
	{
		info += "\n isPlaying";
	}
	info += "\n================================\n";
	return info;
}

int main()
{
	music m("la", "la", "la", "");
	playlist la;
	la.append(m);
	Player test(la);

	cout << test.playingInfo() << endl;
	return 0;
}