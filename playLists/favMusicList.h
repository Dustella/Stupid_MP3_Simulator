#ifndef FAVMUSICLIST_H
#define FAVMUSICLIST_H

#include "playList.h"

class LikeMusicList :public playlist{
private:
	const string playListName="Favorites";
	
public:

	LikeMusicList(){}
	LikeMusicList(vector<music> MList);

};

#endif
