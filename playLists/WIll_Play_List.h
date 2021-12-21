#ifndef WILL_PLAY_LIST_H
#define WILL_PLAY_LIST_H

#include"List.h"
#include<string>
#include<vector>
#include"music.h"
//#include"Player.h"
#include"musicList.h"
//class Player;
class WIll_Play_List: public List{
//  friend class Player;
public:
    WIll_Play_List(musicList L);
    WIll_Play_List(const WIll_Play_List &w);
    WIll_Play_List() = default;

    virtual bool append(music M) /*override*/;//���Ӹ���
    bool pop(int i);//ɾ������
    virtual bool pop(string music_name) /*override*/;
    virtual int getNum() /*override*/;
    ~WIll_Play_List();
    vector<music> The_Music_List();
    

private:
    vector<music> musiclist;//��Ÿ���
    int music_number=0;//��¼����赥�и���������
};

#endif
