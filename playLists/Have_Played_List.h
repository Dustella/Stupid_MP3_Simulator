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
    vector<music>musiclist;//´æ·Å¸èÇú
    int music_number=0;
public:
    Have_Played_List() = default;

    virtual bool Add_Music(music M) /*override*/;
    virtual bool Delete_Music(string music_name) /*override*/;
    ~Have_Played_List();
    virtual int Music_number_in_this_list() /*override*/;
    vector<music> The_Music_List();
    
};


#endif
