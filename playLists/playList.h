#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../music/music.cpp"
#include "List.h"
#include <vector>
#include <string>

class Player;
class playlist : public List
{

    friend void CreateList(string path, string name, playlist *M);
    friend class Player;
    friend playlist operator+(playlist &list1, playlist &list2); //用于合并歌单

private:
    int totalMusicNum = 0; //记录这个歌单中歌曲的数量
    string playListName;   //歌单的名字

public:
    vector<music> musiclist;        //存放歌曲
    playlist(const playlist &list); //复制构造函数
    playlist(){};
    playlist(string playListName, vector<music> Mlist);

    bool append(music M);          //增加歌曲
    void insert(int pos, music M); //
    bool pop(string music_name);   //删除歌曲
    int length();                  //得到长度
    void updateLength();
    void swap(int a, int b);

    void setListName(string a);
    string getListName() const; // 显示播放列表名字
    string getFormattedList();  //显示这个歌单中所有歌曲的名字

    void setPlaylist(playlist ls);

    vector<music> searchByAuthor(string author_name);
    vector<music> searchByTitle(string name);

    music operator[](int i)
    {
        return musiclist[i];
    }
};

#endif // MUSICPLAYER_MUSICLIST_H
