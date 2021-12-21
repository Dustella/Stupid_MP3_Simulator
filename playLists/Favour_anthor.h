#ifndef FAVOUR_ANTHOR_H
#define FAVOUR_ANTHOR_H

#include<vector>
#include<iostream>
#include<string>
#include <set>
#include"music.h"
#include"musicList.h"
#include"LikeMusicList.h"
#include<algorithm>

using namespace std;

class Favour_anthor{
	friend bool operator ==(Favour_anthor a,Favour_anthor b);
	
private :
	string name;
	string sex;
	int age;
	
public:
	vector<music*> The_Music_of_the_anthor;
	vector<string> music_name;
	void sort_by_name(int low,int high);
	string showName();
	string showSex();
	int showAge();
	void Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm);
	Favour_anthor(string name,string sex,int age,vector<musicList> &M,LikeMusicList &LM);
	Favour_anthor(){
		
	}
	void Refresh(vector<musicList> &M,LikeMusicList &LM);//���¸��ֵĸ赥
	~Favour_anthor()=default;
	void showMusic();
};

#endif
