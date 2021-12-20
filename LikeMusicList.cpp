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
bool LikeMusicList::Add_Music(music M){//Ôö¼Ó¸èÇú
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
bool LikeMusicList::Delete_Music(string music_name) {
	for(int i=0;i<music_number;i++)
		{
			if(musiclist[i].showname()==music_name)
				{
					musiclist[i].liked();
					musiclist.erase(musiclist.begin()+i);
					music_number--;
					return true;
				}
		}
	return false;
}
int LikeMusicList:: Music_number_in_this_list(){
	return musiclist.size();
}
string LikeMusicList:: showListName(){
	return list_name;
}
