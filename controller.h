#include <string>
#include <vector>
#include "musicList.h"
#include "likeMusicList.h"
#include "Favour_anthor.h"

class controller
{
private:
    /* data */
public:
    void init();
    void welcome();
    void getFiles(string path, vector<string> &files);
    void CreateList(string path, string name, musicList *M);
    void Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm);
    void Print_All_the_List(const vector<musicList> &The_lists);

};


