#ifndef LIKEMUSICLIST_H
#define LIKEMUSICLIST_H

#include "playList.h"

class LikeMusicList :public musicList{
private:
	const string playListName="Favorites";//
	
public:

	LikeMusicList(){}
	LikeMusicList(vector<music> MList);


};

#endif
