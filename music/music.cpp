#include "../music/music.h"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int music::number = 0;

music::music(string N, string A, string f) : name(N), author(A), music_file(f)
{
    number++;
}
void music::setInfo()
{
}


string music::getName() const
{
    return name;
}
string music::getAuther() const
{
    return author;
}
int music::Music_number()
{
    return number;
}
void music::liked()
{
    this->is_like = !is_like;
}

music::~music()
{
    number--;
}

bool operator==(music &m1, music &m2)
{
    if (m1.name == m2.name && m1.author == m2.author)
        return true;
    else
        return false;
}
bool music::is_liked()
{
    return is_like;
}
void music::play()
{
    char f[1024];
    int i = 0;
    for (i = 0; i < filename.length(); i++)
    {
        f[i] = filename[i];
    }
    filename[i] = 0;
    cout << filename << "is playing" << endl;
    // music_file = fopen(f, "r");
    // return music_file;
    // return music_file;
}
bool operator<(const music &M1, const music &M2)
{
    if (M1.getName() < M2.getName())
        return true;
    else
        return false;
}

bool operator>(const music &M1, const music &M2)
{
    if (M1.getName() > M2.getName())
        return true;
    else
        return false;
}
bool operator<=(const music &M1, const music &M2)
{
    if (M1.getName() <= M2.getName())
        return true;
    else
        return false;
}
string music::getPath()
{
    return path;
}
