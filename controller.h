#include <string>
#include <vector>
#include "likeMusicList.h"
#include "Favour_anthor.h"

class controller
{
private:
    /* data */
public:
    void selection(char choice, LikeMusicList &LM, vector<Favour_anthor> &set_of_anthor, vector<musicList> &The_list_of_musicList);
    char menu();
    void init(LikeMusicList &LM, vector<Favour_anthor> set_of_anthor, vector<musicList> The_list_of_musicList);
    void welcome();
    void getFiles(string path, vector<string> &files);
    void CreateList(string path, string name, musicList *M);
    void Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm);
    void Print_All_the_List(const vector<musicList> &The_lists);
};
