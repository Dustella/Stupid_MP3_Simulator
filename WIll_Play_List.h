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

    virtual bool Add_Music(music M) /*override*/;//增加歌曲
    bool Delete_Music(int i);//删除歌曲
    virtual bool Delete_Music(string music_name) /*override*/;
    virtual int Music_number_in_this_list() /*override*/;
    ~WIll_Play_List();
    vector<music> The_Music_List();
    

private:
    vector<music> musiclist;//存放歌曲
    int music_number=0;//记录这个歌单中歌曲的数量
};

#endif
