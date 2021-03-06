#ifndef playlist_control
#define playlist_control

#include "../store/store.cpp"

class playlistControl
{
private:
    store storage;

public:
    vector<playlist> allLists;
    void refresh();

    void promotListOpt();

    void promotAddGuide();
    void promotDeleteGuide();
    void promotlistManager();

    void printAllLists();
    void printAllMusics(playlist la);

    void addMusic(playlist &ls);
    void removeMusic(playlist &ls);
    void ManageList(playlist &ls);

    playlistControl();
    ~playlistControl();
};

#endif