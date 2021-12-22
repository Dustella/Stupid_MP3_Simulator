#ifndef LIST_H
#define LIST_H
#include "../music/music.h"
#include <string>
#include <vector>

class List
{
public:
	virtual bool append(music M) = 0;		 //
	virtual bool pop(string music_name) = 0; 
	virtual int length() = 0;
	virtual void setListName(string a) = 0;
	string getListName() const;	   // 显示播放列表名字
	virtual string getFormattedList() = 0; //显示这个歌单中所有歌曲的名字

	virtual vector<music> searchByAuthor(string author_name) = 0;
	virtual vector<music> searchByTitle(string name) = 0;
};

#endif
