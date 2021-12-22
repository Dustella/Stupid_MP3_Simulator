#include "playList.h"
#include "music.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


musicList::musicList(const musicList &list)
{ //复制歌单
    playListName = list.playListName;
    musicNumber = list.musicNumber;
    for (auto e : list.musiclist)
    {
        musiclist.push_back(e);
    }
}

string musicList::getFormattedList()
{
    cout.width(40);
    cout << "Name of musics";
    cout.width(40);
    cout << "Author of the music";
    cout << endl;
    for (int i = 0; i < musicNumber; i++)
    {
        cout << i + 1 << " ";
        string name_of_music = musiclist[i].getTitle();
        string author_of_music = musiclist[i].getAuthor();
        cout.width(40);
        cout << name_of_music;
        cout.width(40);
        cout << author_of_music;
        cout << endl;
    }
}

musicList::musicList(string playListName, vector<music> Mlist)
{ //构造函数
    this->playListName = playListName;
    musicNumber = Mlist.size();
    for (int i = 0; i < musicNumber; i++)
    {
        musiclist.push_back(Mlist[i]);
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

    list3.musicNumber = list3.musiclist.size();
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
    musicNumber++;
    return true;
}

void musicList::setListName(string a)
{
    this->playListName = a;
}

bool musicList::pop(string music_name)
{
    for (int i = 0; i < musicNumber; i++)
    {
        if (musiclist[i].getTitle() == music_name)
        {
            musiclist.erase(musiclist.begin() + i);
            musicNumber--;
            return true;
        }
    }
    return false;
}


string musicList::getListName() const
{
    return playListName;
}


int musicList::getNum()
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

}

