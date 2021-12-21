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
	bool append(music M);//���Ӹ���
	bool pop(string music_name);//ɾ������
	int getNum();
	string showListName();
};

#endif
