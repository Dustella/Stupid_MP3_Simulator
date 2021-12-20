//
// Created by Mac on 2021/11/30.
//

#ifndef MUSICPLAYER_MUSICLIST_H
#define MUSICPLAYER_MUSICLIST_H

#include "music.h"
#include "List.h"
#include <vector>
#include <string>
class WIll_Play_List;
class Player;
class musicList : public List
{
    friend void CreateList(string path, string name, musicList *M);
    friend class Player;
    friend musicList operator+(musicList &list1, musicList &list2); //用于合并歌单
    friend class WIll_Play_List;

private:
    int music_number = 0;   //记录这个歌单中歌曲的数量
    string list_name;       //歌单的名字
    static int list_number; //歌单的数量
public:
    vector<music> musiclist; //存放歌曲
    musicList(){};
    musicList(string list_name, vector<music> Mlist);
    musicList(const musicList &list); //复制构造函数
    musicList(vector<music> Mlist);
    string showListName() const;
    void PrintMusiclist() /*const*/; //显示这个歌单中所有歌曲的名字
    int static List_number();        //显示歌单数目的函数
    void Reset_ListName(string new_name);
    bool Add_Music(music M);              //增加歌曲
    bool Delete_Music(string music_name); //删除歌曲
    int Music_number_in_this_list();
    vector<string> SearchAuthor(string author_name);
    bool search_music(string name);
    void sort_by_name(int low, int high);
    void Operate_the_List();
};

#endif // MUSICPLAYER_MUSICLIST_H
