#include <string>
#include <vector>
#include "likeMusicList.h"
#include "Favour_anthor.h"

class controller
{
private:
    /* data */
public:
    static void readConfig(string path,vector<string> &lines);
    static void selection(char choice, LikeMusicList &LM, vector<Favour_anthor> &set_of_anthor, vector<musicList> &The_list_of_musicList);
    static char menu();
    static void init(LikeMusicList &LM, vector<Favour_anthor> set_of_anthor, vector<musicList> The_list_of_musicList);
    static void welcome();
    static void getFiles(string path, vector<string> &files);
    static void CreateList(string path, string name, musicList *M);
    static void Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm);
    static void Print_All_the_List(const vector<musicList> &The_lists);
};
