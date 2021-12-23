#include "Player.h"
#include "../playLists/nowPlayinglist.cpp"
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
	cout << nowPlaying.length() << endl;
	if (nowPlaying.getNowPlayingID() == nowPlaying.length() - 1)
	{

		nowPlaying.setNowPlayingID(0);
	}
	else
	{
		nowPlaying.setNowPlayingID(nowPlaying.getNowPlayingID() + 1);
	}
}

void Player::previousPlay()
{
	if (nowPlaying.getNowPlayingID() == 0)
	{
		nowPlaying.setNowPlayingID(nowPlaying.length() - 1);
	}
	else
	{

		nowPlaying.setNowPlayingID(nowPlaying.getNowPlayingID() - 1);
	}
}

Player::Player(playlist M) : nowPlaying(M)
{
}

void Player::setPlaylist(playlist ls)
{
	if(ls.length() == 0){
		cout << "empty playlist" << endl;
		music tmp("NULL","NULL","NULL","NULL");
		ls.append(tmp);
	}
	nowPlaying.setPlaylist(ls);
}

string Player::playingInfo()
{
	string info;
	info += "================================\n";
	info += "Now Playing: \n";
	info += "Title: ";
	info += nowPlaying.getNowPlayingMusic().getTitle();
	info += "\nArtist: ";
	info += nowPlaying.getNowPlayingMusic().getAuthor();
	info += "\nAlbum: ";
	info += nowPlaying.getNowPlayingMusic().getAlbum();
	if (isPaused)
	{
		info += "\nisPaused";
	}
	else
	{
		info += "\nisPlaying";
	}
	info += "\n================================\n";
	return info;
}

// int main()
// {
// 	music m1("la", "la", "la", "");
// 	music m2("la1", "la", "la", "");
// 	music m3("la12", "la", "la", "");
// 	playlist la;
// 	la.append(m1);
// 	la.append(m2);
// 	la.append(m3);
// 	Player test(la);
// 	test.play();
// 	cout << test.playingInfo() << endl;
// 	test.nextPlay();
// 	cout << test.playingInfo() << endl;
// 	test.nextPlay();
// 	cout << test.playingInfo() << endl;
// 	test.nextPlay();
// 	cout << test.playingInfo() << endl;
// 	test.nextPlay();
// 	cout << test.playingInfo() << endl;

// 	return 0;
// }
