#include "WIll_Play_List.h"
WIll_Play_List::WIll_Play_List(musicList L)
{
    musiclist = L.musiclist;
    music_number = musiclist.size();
}

bool WIll_Play_List::append(music M)
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

bool WIll_Play_List::pop(string music_name)
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

bool WIll_Play_List::pop(int i)
{
    if (i >= music_number)
        return false;
    else
    {
        musiclist.erase(musiclist.begin() + i);
        music_number--;
        return true;
    }
}

int WIll_Play_List::getNum()
{
    return music_number;
}

WIll_Play_List::~WIll_Play_List()
{
}

vector<music> WIll_Play_List::The_Music_List()
{
    return musiclist;
}

WIll_Play_List::WIll_Play_List(const WIll_Play_List &w)
{
    music_number = w.music_number;
    for (int i = 0; i < w.music_number; i++)
    {
        musiclist.push_back(w.musiclist[i]);
    }
}
