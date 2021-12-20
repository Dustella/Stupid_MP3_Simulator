//
// Created by Mac on 2021/11/30.
//

#include "musicList.h"
#include "music.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


int musicList::list_number = 0;
musicList::musicList(const musicList &list)
{ //复制歌单
    list_name = list.list_name;
    music_number = list.music_number;
    for (auto e : list.musiclist)
    {
        musiclist.push_back(e);
    }
    list_number++;
}

int musicList::List_number()
{ //显示歌单的函数
    return list_number;
}

void musicList::PrintMusiclist()
{
    cout.width(40);
    cout << "Name of musics";
    cout.width(40);
    cout << "Author of the music";
    cout << endl;
    for (int i = 0; i < music_number; i++)
    {
        cout << i + 1 << " ";
        string name_of_music = musiclist[i].getName();
        string author_of_music = musiclist[i].getAuther();
        cout.width(40);
        cout << name_of_music;
        cout.width(40);
        cout << author_of_music;
        cout << endl;
    }
}

musicList::musicList(string list_name, vector<music> Mlist)
{ //构造函数
    this->list_name = list_name;
    music_number = Mlist.size();
    for (int i = 0; i < music_number; i++)
    {
        musiclist.push_back(Mlist[i]);
    }
    list_number++;
}

musicList operator+(musicList &list1, musicList &list2)
{ //合并歌单
    musicList list3;
    list3.list_name = list1.list_name + " and " + list2.list_name;
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

    list3.music_number = list3.musiclist.size();
    return list3;
}

void musicList::Reset_ListName(string new_name)
{
    list_name = new_name;
}

bool musicList::Add_Music(music M)
{
    for (auto e : musiclist)
    {
        if (e == M)
            return false;
    }
    musiclist.push_back(M);
    music_number++;
    return true;
}

bool musicList::Delete_Music(string music_name)
{
    for (int i = 0; i < music_number; i++)
    {
        if (musiclist[i].getName() == music_name)
        {
            musiclist.erase(musiclist.begin() + i);
            music_number--;
            return true;
        }
    }
    return false;
}
string musicList::showListName() const
{
    return list_name;
}
int musicList::Music_number_in_this_list()
{
    return sizeof(musiclist);
}
vector<string> musicList::SearchAuthor(string author_name)
{
    vector<string> Music;
    for (auto e : musiclist)
    {
        if (e.getAuther() == author_name)
        {
            string name = e.getName();
            Music.push_back(name);
        }
    }
    return Music;
}
bool musicList::search_music(string name)
{
    int flag = 0;
    set<string> author_name;
    for (auto e : musiclist)
    {
        if (e.getName() == name)
        {
            author_name.insert(e.getAuther());
            flag = 1;
        }
    }
    if (flag)
    {
        cout.width(40);
        cout << "歌曲名称"
             << "作者" << endl;
        for (auto e : author_name)
        {
            cout.widen(40);
            cout << name << e << endl;
        }
        cout << "搜索成功" << endl;
    }
    else
    {
        cout << "没有您寻找的歌曲" << endl;
    }
    return flag;
}

void musicList::sort_by_name(int low, int high)
{
    if (low < high)
    {
        int i = low, j = high;
        music x = musiclist[low];
        while (i < j)
        {
            while (i < j && musiclist[j] > x)
                j--;
            if (i < j)
                musiclist[i++] = musiclist[j];
            while (i < j && musiclist[i] <= x)
                i++;
            if (i < j)
                musiclist[j--] = musiclist[i];
        }
        musiclist[i] = x;
        sort_by_name(low, i - 1);
        sort_by_name(i + 1, high);
    }
}

void musicList::Operate_the_List()
{
    cout << "欢迎使用歌单操作界面" << endl;
    cout << "输入1查看单前歌单的全部歌曲" << endl;
    cout << "输入2进入歌曲检索界面" << endl;
    cout << "输入3进入歌手检索界面" << endl;
    cout << "输入4进入歌曲数量查看界面" << endl;
    cout << "输入5重新设置歌名" << endl;
    cout << "输入6进行歌曲添加" << endl;
    cout << "输入7进行歌曲删除" << endl;
    cout << "输入0结束本项功能" << endl;
    int choose;
    cin >> choose;
    int flag = 1;
    while (flag)
    {
        switch (choose)
        {
        case 1:
        {
            PrintMusiclist();
        }
        break;
        case 2:
        {
            cout << "请输入进行检索的歌曲名" << endl;
            string name;
            cin >> name;
            search_music(name);
        }
        break;
        case 3:
        {
            cout << "请输入需要进行检索的歌手名" << endl;
            string name;
            cin >> name;
            vector<string> s;
            s = SearchAuthor(name);
            if (s.size() == 0)
            {
                cout << "没有这位歌手的作品" << endl;
            }
            else
            {
                for (auto e : s)
                {
                    cout.width(30);
                    cout << e << endl;
                }
            }
        }
        break;
        case 4:
        {
            cout << Music_number_in_this_list() << endl;
        }
        break;
        case 5:
        {
            cout << "请输入歌单的新名字" << endl;
            string new_name;
            cin >> new_name;
            Reset_ListName(new_name);
        }
        break;
        case 6:
        {
            cout << "请输入歌曲名" << endl;
            string name;
            cin >> name;
            cout << "请输入作者" << endl;
            string author;
            cin >> author;
            music Mu(name, author, nullptr);
            Add_Music(Mu);
        }
        break;
        case 7:
        {
            cout << "请输入您需要删除的歌曲" << endl;
            string name;
            cin >> name;
            Delete_Music(name);
        }
        break;
        case 0:
        {
            flag = 0;
        }
        break;
        }

        cin >> flag;
    }
}