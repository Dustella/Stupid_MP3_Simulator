#include "playList.h"
#include "music.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#pragma region constructor

musicList::musicList(const musicList &list)
{ //复制歌单
    playListName = list.playListName;
    totalMusicNum = list.totalMusicNum;
    for (auto e : list.musiclist)
    {
        musiclist.push_back(e);
    }
}

musicList::musicList(string playListName, vector<music> Mlist)
{ //构造函数
    this->playListName = playListName;
    totalMusicNum = Mlist.size();
    for (int i = 0; i < totalMusicNum; i++)
    {
        musiclist.push_back(Mlist[i]);
    }
}

#pragma endregion constructor

string musicList::getFormattedList()
{
    string result = "";
    result += "Name of musics\n";
    result += "Author of the music\n";
    for (int i = 0; i < totalMusicNum; i++)
    {
        cout << i + 1 << " ";
        result += musiclist[i].getTitle() + "\n";
        result += musiclist[i].getAuthor() + "\n";
    }
}

#pragma region operaterOverrides
musicList operator+(musicList &list1, musicList &list2)
{ //合并歌单
    musicList list3;

    list3.playListName = list1.playListName + " and " + list2.playListName;
    for (auto e : list1.musiclist)
    {
        list3.musiclist.push_back(e);
    }
    for (auto e : list2.musiclist)
    {
        for (auto s : list1.musiclist)
            if (e == s)
                continue;
        list3.musiclist.push_back(e);
    }

    list3.totalMusicNum = list3.musiclist.size();
    return list3;
}

#pragma endregion operatorOverride

bool musicList::append(music M)
{
    for (auto e : musiclist)
    {
        if (e == M)
            return false;
    }
    musiclist.push_back(M);
    totalMusicNum++;
    return true;
}

void musicList::updateLength()
{
    this->totalMusicNum = musiclist.size();
}

void musicList::swap(int a, int b){
    music tmp=musiclist[a];
    musiclist[a]=musiclist[b];
    musiclist[b]=tmp;
}

void musicList::setListName(string a)
{
    this->playListName = a;
}

bool musicList::pop(string music_name)
{
    for (int i = 0; i < totalMusicNum; i++)
    {
        if (musiclist[i].getTitle() == music_name)
        {
            musiclist.erase(musiclist.begin() + i);
            totalMusicNum--;
            return true;
        }
    }
    return false;
}

string musicList::getListName() const
{
    return playListName;
}

int musicList::length()
{
    return sizeof(musiclist);
}

vector<music> musicList::searchByAuthor(string autherName)
{
    vector<music> result;
    for (auto e : musiclist)
    {
        if (e.getAuthor() == autherName)
        {
            result.push_back(e);
        }
    }
    return result;
}

vector<music> musicList::searchByTitle(string titleName)
{
    vector<music> result;

    for (auto e : musiclist)
    {
        if (e.getTitle() == titleName)
        {
            result.push_back(e);
        }
    }
    return result;
}
