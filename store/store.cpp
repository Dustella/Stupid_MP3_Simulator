#include "store.h"
#include "fstream"
#include "sstream"
#include "../utils/CJsonObject.hpp"

using namespace neb;

store::store() : data("{}")
{
    string ori = fetchStore();
    data.Parse(ori);
}

store::~store() {}

vector<playlist> store::getAllPlaylists()
{
    vector<playlist> result;

    string playlistName;
    CJsonObject playlistObject;
    while (data.GetKey(playlistName))
    {
        if (data.Get(playlistName, playlistObject))
        {
            playlist tmp;
            for (int i = 0; i < data[playlistName].GetArraySize(); i++)
            {
                string Title;
                data[playlistName][i].Get("Title", Title);

                string Album;
                data[playlistName][i].Get("Album", Album);

                string Author;
                data[playlistName][i].Get("Author", Author);

                string path;
                data[playlistName][i].Get("Path", path);

                music toAdd(Title, Author, Album, path);

                tmp.append(toAdd);
            }
            result.push_back(tmp);
        }
    }

    return result;
}

void store::writeStore()
{
    ofstream OsWrite("../store.json");
    string content = data.ToFormattedString();
    OsWrite << content;
    OsWrite.close();
}

string store::fetchStore()
{
    fstream musicJSON;
    musicJSON.open("../store.json");
    ostringstream buf;
    char ch;
    while (musicJSON.get(ch) && buf)
    {
        buf.put(ch);
    }
    musicJSON.close();
    return buf.str();
}

void store::addPlaylist(playlist ls)
{
    string name = ls.getListName();
    data.AddEmptySubArray(name);
}

void store::syncPlaylist(playlist ls)
{
    string name = ls.getListName();
    cout << name << endl;
    if (data.GetKey(name))
    {
        cout <<"is"<< endl;

        data.AddEmptySubArray(ls.getListName());
    }
    for (int i = 0; i < ls.length(); i++)
    {
        music tmp = ls[i];
        CJsonObject musicObject;
        musicObject.Add("Title", tmp.getTitle());
        musicObject.Add("Album", tmp.getAlbum());
        musicObject.Add("path", tmp.getPath());
        musicObject.Add("Author", tmp.getAuthor());
        data[ls.getListName()].Add(musicObject);
    }
}

int main()
{

    music m1("la", "la", "la", "");
    music m2("la1", "la", "la", "");
    music m3("la12", "la", "la", "");
    playlist la;
    la.append(m1);
    la.append(m2);
    la.append(m3);
    la.setListName("laa");
    store st;
    // st.addPlaylist(la);
    st.syncPlaylist(la);
    st.writeStore();
    st.getAllPlaylists();
    cout << st.data.ToFormattedString() << endl;
}