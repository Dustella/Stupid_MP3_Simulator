#ifndef LIKEMUSICLIST_H
#define LIKEMUSICLIST_H

#include "musicList.h"

class LikeMusicList :public musicList{
private:
	const string list_name="The music that I love";//歌单的名字
	int music_number=0;//记录这个歌单中歌曲的数量
public:
	vector<music> musiclist;
	LikeMusicList(){}
	LikeMusicList(vector<music> MList);
	bool Add_Music(music M);//增加歌曲
	bool Delete_Music(string music_name);//删除歌曲
	int Music_number_in_this_list();
	string showListName();
};

#endif
