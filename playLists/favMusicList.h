#ifndef LIKEMUSICLIST_H
#define LIKEMUSICLIST_H

#include "playList.h"

class LikeMusicList :public musicList{
private:
	const string playListName="The music that I love";//�赥������
	int totalMusicNum=0;//��¼����赥�и���������
public:
	vector<music> musiclist;
	LikeMusicList(){}
	LikeMusicList(vector<music> MList);
	bool append(music M);//���Ӹ���
	bool pop(string music_name);//ɾ������
	int getNum();
	string getListName();
};

#endif
