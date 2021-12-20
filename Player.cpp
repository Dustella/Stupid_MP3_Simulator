#include "Player.h"
#include "musicList.h"
#include "LikeMusicList.h"
#include <vector>
#include <string>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>

using namespace std;

void Player::Random_Play()
{
	int n = LIST->musiclist.size();
	vector<int> have_played;
	vector<int> will_play;
	for (int i = 0; i < n; i++)
	{
		will_play.push_back(i);
	}
	srand((int)time(0));
	while (will_play.size() != 0)
	{
		int j = rand() % will_play.size();
		Play(LIST->musiclist[will_play[j]]);
		will_play.erase(will_play.begin() + j);
	}
}
void Player::Order_Play()
{
	for (auto e : LIST->musiclist)
	{
		Play(e);
	}
}

void Player::Play(music &M)
{
	char path[1024];
	string p = M.Play();
	for (int i = 0; i < p.length(); i++)
	{
		path[i] = p[i];
	}
	char open[] = "open ";
	char play[] = "play ";
	char alias[] = " alias s1";
	strcat(open, path);
	strcat(open, alias);
	strcat(play, path);
	mciSendString(TEXT(open), NULL, 0, NULL);
	mciSendString(TEXT(play), NULL, 0, NULL);
	Sleep(180000); 
	mciSendString(TEXT("close S1"), NULL, 0, NULL);
}

Player::Player(musicList *M) : LIST(M)
{
}
