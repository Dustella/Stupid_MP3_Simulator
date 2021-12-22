#include "playControl.h"
#include <string>


playControl::playControl(){
    playlist newP;
    player.setPlaylist(newP);
}

string playControl::nowPlaying()
{
    string result;
    result += "================================";
    result += "";
    return result;
}