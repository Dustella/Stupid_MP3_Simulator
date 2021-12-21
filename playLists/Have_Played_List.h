#ifndef HAVE_PLAYED_LIST_H
#define HAVE_PLAYED_LIST_H

#include"List.h"
#include"music.h"
#include<vector>
//#include "Player.h"

using namespace std;


class Have_Played_List:public List{
//  friend class Player;
private:
    vector<music>musiclist;//��Ÿ���
    int music_number=0;
public:
    Have_Played_List() = default;

    virtual bool append(music M) /*override*/;
    virtual bool pop(string music_name) /*override*/;
    ~Have_Played_List();
    virtual int getNum() /*override*/;
    vector<music> The_Music_List();
    
};


#endif
