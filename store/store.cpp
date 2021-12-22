#include "store.h"
#include "fstream"
#include "sstream"
#include "../utils/CJsonObject.hpp"

void store::writeStore(string content)
{
    ofstream OsWrite;
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



int main()
{
    cout << "lala" << endl;
    store st;
    // cout << st.data.ToFormattedString() << endl;
}