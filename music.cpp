#include "music.h"
#include <string>
#include "libzplay.h"
#include <string.h>

using namespace libZPlay;

int music::number = 0;

music::music(string N, string A, FILE *f) : name(N), author(A), music_file(f)
{
    number++;
}
// music::music(string N, string A, string filename) : name(N), author(A), filename(filename)
// {
//     number++;
// }
// music::music(string N, string A, string filename, FILE *f = nullptr) : name(N), author(A), filename(filename), music_file(f)
// {
//     number++;
// }
// // music::
// music::music(string N,string A,string filename,string path,FILE* f=nullptr):name(N),author(A),filename(filename),path(path),music_file(f)
// {
//     number++;
// }
void music::setInfo()
{
    ZPlay *file = CreateZPlay();
    const char *location = path.c_str();
    TID3InfoEx id3_info;
    if (file->LoadFileID3Ex(location, sfAutodetect, &id3_info, 1))
    {
        this->name = id3_info.Title;
        this->author = id3_info.Artist;
    }
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
FILE *music::play()
{
    char f[1024];
    int i = 0;
    for (i = 0; i < filename.length(); i++)
    {
        f[i] = filename[i];
    }
    filename[i] = 0;
    music_file = fopen(f, "r");
    return music_file;
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
