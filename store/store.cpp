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
}

int main()
{
    playlist la;
    la.setListName("lalala");
    store st;
    // st.addPlaylist(la);
    st.writeStore();
    cout << st.data.ToFormattedString() << endl;
}