#ifndef LIST_H
#define LIST_H
#include "music.h"
#include <string>

class List
{
public:
	virtual bool append(music M) = 0;			  //���Ӹ���
	virtual bool pop(string music_name) = 0; //ɾ������
	virtual int getNum() = 0;
	// virtual ~List();
};

#endif
