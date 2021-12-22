#include "playlistControl.h"

playlistControl::playlistControl() {}

playlistControl::~playlistControl() {}

void playlistControl::init()
{
    allLists = storage.getAllPlaylists();
    for (playlist i : allLists)
    {
        cout << i.getListName() << endl;
    }
}

void playlistControl::promotListOpt()
{
    cout << "List Operations" << endl;
    cout << "================================" << endl;
    cout << "1. Back to main Menu" << endl;
    cout << "2. Add a new list" << endl;
    cout << "3. Modify a list" << endl;
    cout << "4. Remove a list" << endl;
    int i;
    cin >> i;
}

void playlistControl::promotAddGuide()
{
    cout << "Adding a new list" << endl;
    cout << "================================" << endl;
    cout << "Take a list name: " << endl;
    string name;
    cin >> name;
    playlist newPlaylist;
    newPlaylist.setListName(name);
    // clear
}

void playlistControl::addMusic(playlist &ls)
{
    cout << "Adding Music to a list" << endl;
    cout << "================================" << endl;
    cout << "Input music Name, \'q\' to end" << endl;

    string musicName;
    cin >> musicName;
    if (musicName == "q")
    {
        return;
    }

    cout << "Input music Album" << endl;
    string musicAlbum;
    cin >> musicAlbum;

    cout << "Input music Author" << endl;
    string musicAuthor;
    cin >> musicAuthor;

    music newMusic(musicName, musicAlbum, musicAuthor, "");
    ls.append(newMusic);

    cout << "Add Music Success" << endl;
    addMusic(ls);
}

int main()
{
    playlistControl ctl;
    ctl.init();
    return 0;
}