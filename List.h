#ifndef LIST_H
#define LIST_H
#include"music.h"
#include <string>

class List {
public:
	virtual bool Add_Music(music M)=0;//���Ӹ���
	virtual bool Delete_Music(string music_name)=0;//ɾ������
	virtual int Music_number_in_this_list()=0;
	// virtual ~List();
};


#endif
