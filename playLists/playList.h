#ifndef PLAYLIST_H
#define PLAYLIST_H

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

    int totalMusicNum = 0;   //记录这个歌单中歌曲的数量
    string playListName;     //歌单的名字
    vector<music> musiclist; //存放歌曲

public:
    musicList(){};
    musicList(string playListName, vector<music> Mlist);
    musicList(const musicList &list); //复制构造函数

    bool append(music M);        //增加歌曲
    bool pop(string music_name); //删除歌曲
    int length();                //得到长度
    void updateLength();
    void swap(int a, int b);

    void setListName(string a);
    string getListName() const; // 显示播放列表名字
    string getFormattedList();  //显示这个歌单中所有歌曲的名字


    vector<music> searchByAuthor(string author_name);
    vector<music> searchByTitle(string name);
};

#endif // MUSICPLAYER_MUSICLIST_H
