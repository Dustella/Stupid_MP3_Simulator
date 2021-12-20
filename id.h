#ifndef ID_H
#define ID_H
#include"musicList.h"
#include<string>
#include<vector>
#include"LikeMusicList.h"
using namespace std;
class id{
private:
	string ID;
	string password;
	vector<musicList> user_musicList;
	LikeMusicList my_favourite_music;
public:
	id(){};
	id(string i,string p):ID(i),password(p)
	{}
	bool landing(string password_i);//ÓÃÓÚµÇÂ½
	void Add_new_musicList();
	
};

#endif
