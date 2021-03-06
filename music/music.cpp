#include "music.h"
#include <string>
#include <string.h>

#include <iostream>
using namespace std;

music::music(string N, string A, string K, string f) : Title(N), Author(A), Album(K), path(f) {}

music::music() {}

void music::setInfo(string title, string Author, string Album, string path)
{
    this->Title = title;
    this->Author = Author;
    this->path = path;
    this->Album = Album;
}

#pragma region operatorOverride
bool operator==(music &m1, music &m2)
{
    if (m1.Title == m2.Title && m1.Author == m2.Author)
        return true;
    else
        return false;
}

bool operator<(const music &M1, const music &M2)
{
    if (M1.getTitle() < M2.getTitle())
        return true;
    else
        return false;
}

bool operator>(const music &M1, const music &M2)
{
    if (M1.getTitle() > M2.getTitle())
        return true;
    else
        return false;
}

bool operator<=(const music &M1, const music &M2)
{
    if (M1.getTitle() <= M2.getTitle())
        return true;
    else
        return false;
}

#pragma endregion operatorOverride

#pragma region getSet

string music::getPath() const
{
    return path;
}

string music::getTitle() const { return Title; }

string music::getAuthor() const { return Author; }

string music::getAlbum() const { return Album; }

void music::setPath(string path)
{
    this->path = path;
}

void music::setTitle(string title) { this->Title = title; }

void music::setAuthor(string author) { this->Author = author; }

void music::setAlbum(string album) { this->Album = album; }

void music::setLiked() { this->Liked = true; }

void music::setUnliked() { this->Liked = false; }

string music::constuctInfo()
{
    return "";
}

#pragma endregion getSet
