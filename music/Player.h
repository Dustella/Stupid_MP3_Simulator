#ifndef PLAYER_H
#define PLAYER_H

#include"music.h"
#include"musicList.h"

using namespace std;

class Player {
public:
	void Random_Play();
	void Order_Play();
	void Play(music &M);
	Player(musicList *M);
	Player();
private:
	musicList* LIST;

};


#endif
