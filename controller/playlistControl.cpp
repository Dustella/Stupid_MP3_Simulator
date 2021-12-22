#include "playlistControl.h"

playlistControl::playlistControl()
{
    refresh();
}

playlistControl::~playlistControl() {}

void playlistControl::refresh()
{
    allLists = storage.getAllPlaylists();
}

void playlistControl::printAllLists()
{
    for (int i = 0; i < allLists.size(); i++)
    {
        cout << i << ". " << allLists[i].getListName() << endl;
    }
}

void playlistControl::printAllMusics(playlist a)
{
    for (int i = 0; i < a.length(); i++)
    {
        cout << i << ". " << a[i].getTitle() << endl;
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
    switch (i)
    {
    case 1:
    {
        return;
    }
    case 2:
    {
        promotAddGuide();
        break;
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        break;
    }
    default:
    {
        cout << "Input error" << endl;
    }
    break;
    }
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

    addMusic(newPlaylist);

    storage.syncPlaylist(newPlaylist);
    refresh();
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

void playlistControl::removeMusic(playlist &ls)
{
    cout << "Deleting Music from a list" << endl;
    cout << "================================" << endl;
    cout << "Input music Name, \'q\' to end" << endl;

    string musicName;
    cin >> musicName;
    if (musicName == "q")
    {
        return;
    }

    ls.pop(musicName);

    cout << "Del Music Success" << endl;
    removeMusic(ls);
}

void playlistControl::promotDeleteGuide()
{
    cout << "Deleting lists" << endl;
    cout << "================================" << endl;
    printAllLists();
    cout << "================================" << endl;
    cout << "Input the list to delete" << endl;

    string del;
    cin >> del;
    if (del == "nowPlayinglist")
    {
        cout << "Dangerous Operation, Abort..." << endl;
        return;
    }
    storage.deletePlaylist(del);
    cout << "Success!" << endl;
    return;
}

void playlistControl::promotlistManager()
{
    cout << "Select the list to manage" << endl;
    cout << "================================" << endl;
    refresh();
    printAllLists();
    cout << "================================" << endl;
    cout << "Input the list to manage" << endl;
    int a;
    cin >> a;
    ManageList(allLists[a]);
}

void playlistControl::ManageList(playlist &ls)
{
    cout << "Manage " << ls.getListName() << endl;
    cout << "There are musics in the list" << endl;
    cout << "================================" << endl;
    printAllMusics(ls);
    cout << "================================" << endl;
    cout << "1 to del, 2 to add" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        removeMusic(ls);
        break;
    }
    case 2:
    {
        addMusic(ls);
        break;
    }
    default:
    {
        cout << "Input error" << endl;
    }
    }
    storage.syncPlaylist(ls);
    return;
}

int main()
{
    playlistControl ctl;
    ctl.refresh();
    return 0;
}