#include "favMusicList.h"
LikeMusicList::LikeMusicList(vector<music> MList)
{
	for(auto e:MList)
	{
		if(e.is_liked()==false)
			e.liked();
		musiclist.push_back(e);
	}
	totalMusicNum=MList.size();
}
bool LikeMusicList::append(music M){//���Ӹ���
	for(auto e:musiclist)
		{
			if(e==M)
				return false;
		}
	M.liked();
	musiclist.push_back(M);
	totalMusicNum++;
	return true;
}
bool LikeMusicList::pop(string music_name) {
	for(int i=0;i<totalMusicNum;i++)
		{
			if(musiclist[i].getName()==music_name)
				{
					musiclist[i].liked();
					musiclist.erase(musiclist.begin()+i);
					totalMusicNum--;
					return true;
				}
		}
	return false;
}
int LikeMusicList:: getNum(){
	return musiclist.size();
}
string LikeMusicList:: getListName(){
	return playListName;
}
