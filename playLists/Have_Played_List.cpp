#include "Have_Played_List.h"
bool Have_Played_List:: Add_Music(music M){
    for(auto e:musiclist)
    {
        if(e==M)
            return false;
    }
    musiclist.push_back(M);
    music_number++;
    return true;
}

bool Have_Played_List:: Delete_Music(string music_name){
    for(int i=0;i<music_number;i++)
    {
        if(musiclist[i].getName()==music_name)
        {
            musiclist.erase(musiclist.begin()+i);
            music_number--;
            return true;
        }
    }
    return false;
}
int Have_Played_List:: Music_number_in_this_list(){
    return music_number;
}
Have_Played_List::~Have_Played_List(){
}
vector<music> Have_Played_List:: The_Music_List(){
    return musiclist;
}
