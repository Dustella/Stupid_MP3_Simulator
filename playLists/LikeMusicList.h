#ifndef LIKEMUSICLIST_H
#define LIKEMUSICLIST_H

#include "musicList.h"

class LikeMusicList :public musicList{
private:
	const string list_name="The music that I love";//�赥������
	int music_number=0;//��¼����赥�и���������
public:
	vector<music> musiclist;
	LikeMusicList(){}
	LikeMusicList(vector<music> MList);
	bool Add_Music(music M);//���Ӹ���
	bool Delete_Music(string music_name);//ɾ������
	int Music_number_in_this_list();
	string showListName();
};

#endif
