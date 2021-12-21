#include "LikeMusicList.h"
LikeMusicList::LikeMusicList(vector<music> MList)
{
	for(auto e:MList)
	{
		if(e.is_liked()==false)
			e.liked();
		musiclist.push_back(e);
	}
	music_number=MList.size();
}
bool LikeMusicList::append(music M){//���Ӹ���
	for(auto e:musiclist)
		{
			if(e==M)
				return false;
		}
	M.liked();
	musiclist.push_back(M);
	music_number++;
	return true;
}
bool LikeMusicList::pop(string music_name) {
	for(int i=0;i<music_number;i++)
		{
			if(musiclist[i].getName()==music_name)
				{
					musiclist[i].liked();
					musiclist.erase(musiclist.begin()+i);
					music_number--;
					return true;
				}
		}
	return false;
}
int LikeMusicList:: getNum(){
	return musiclist.size();
}
string LikeMusicList:: showListName(){
	return list_name;
}
