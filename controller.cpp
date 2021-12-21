#include <iostream>
#include "controller.h"
#include "music.cpp"
#include "musicList.cpp"
#include "LikeMusicList.cpp"
#include "Favour_anthor.cpp"
#include <windows.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

#include <io.h>

void controller::readConfig(string filePath, vector<string> &lines)
{
    filePath += 'music_list_information.txt';
    ifstream inFile;
    inFile.open(filePath);
    string line;
    int i = 0;
    while (getline(inFile, line))
    {
        lines.push_back(line);
        cout << line << endl;
        i++;
    }
}

// void controller::getFiles(string ORING, vector<string> &files)
void getFiles(string ORING, vector<string> &files)
{
    // cout<<"hhhh"<<endl;
    long hFile = 0;
    //文件信息，声明一个存储文件信息的结构体
    struct _finddata_t fileinfo;
    string p;                                                                         //字符串，存放路径
    if ((hFile = _findfirst(p.assign(ORING).append("\\*").c_str(), &fileinfo)) != -1) //若查找成功，则进入
    {
        do
        {
            //如果是目录,迭代之（即文件夹内还有文件夹）
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                //文件名不等于"."&&文件名不等于".."
                //判断时，两者都要忽略，不然就无限递归跳不出去了！
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(ORING).append("\\").append(fileinfo.name), files);
            }
            //如果不是,加入列表
            else
            {
                files.push_back(p.assign(ORING).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose函数结束查找
        _findclose(hFile);
    }
}

void controller::CreateList(string ORING, string name, musicList *M)
{
    cout << ORING << " " << name << endl;
    cout << "CreatingList" << endl;
    // M->setListName(name);
    vector<string> path;

    readConfig(ORING, path);
    if (path.size() == 0)
    {
        string s1 = "D:\\music\\天路-韩红.mp3";
        path.push_back(s1);
    }
    // M->setListNumber(path.size());
    cout << path.size() << endl;
    for (auto e : path)
    {

        string music_name = "天路";
        string author = "韩红";
        music Mu(music_name, author, e);
    }
    M->sort_by_name(0, M->musiclist.size() - 1);
}

void controller::Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm)
{
    cout << "请输入您希望进行操作的歌手的索引" << endl;
    int i = 0;
    for (auto e : s)
    {
        cout.width(20);
        cout << i << " " << e.showName() << endl;
    }
    int index;
    cin >> index;
    while (index > s.size())
    {
        cout << "输入的索引过大，请重新输入" << endl;
        cin >> index;
    }
    (s[index]).Operate_The_author(s, m, lm);
}

void controller::Print_All_the_List(const vector<musicList> &The_lists)
{
    for (auto M : The_lists)
    {
        cout.width(30);
        cout << M.showListName();
        cout << endl;
        M.PrintMusiclist();
    }
}

char controller::menu()
{
    char f;
    cout << "查看现有所有歌单具体情况请输入1" << endl;
    cout << "标记喜欢的歌曲请输入2" << endl;
    cout << "查看喜欢的歌曲请输入3" << endl;
    cout << "合并歌单请输入4" << endl;
    cout << "对于特定歌单进行操作请输入5" << endl;
    cout << "操作喜欢的歌曲请输入6" << endl;
    cout << "创建喜欢的歌手请输入7" << endl;
    cout << "对歌手进行操作输入8" << endl;
    cout << "查看所有歌曲数目请输入9" << endl;
    cout << "打开播放器播放音乐输入o" << endl;
    cout << "退出输入'q" << endl;
    cin >> f;
    return f;
}

void controller::init(LikeMusicList &LM, vector<Favour_anthor> set_of_anthor, vector<musicList> The_list_of_musicList)
{ //初始化播放列表
    while (1)
    {

        cout << "请输入歌单的路径" << endl;
        string path;
        cin >> path;
        vector<string> filename;
        set<char> judge;
        for (auto e : filename)
        {
            int n = e.size();
            judge.insert(e[n - 1]);
        }
        string name;
        // if (judge.size() == 2)
        // {
        cout << "请输入歌单的名称" << endl;
        cin >> name;
        // }

        musicList M;
        CreateList(path, name, &M);
        The_list_of_musicList.push_back(M);
        cout << "您是否希望继续创建新的歌单(y/n）:";
        char f;
        cin >> f;
        if (f == 'n')
        {
            break;
        }
    }
}

void controller::welcome()
{
    cout << "=====================欢迎使用音乐管理系统===================" << endl;
}
void controller::selection(char choice, LikeMusicList &LM, vector<Favour_anthor> &set_of_anthor, vector<musicList> &The_list_of_musicList)
{
    switch (choice)
    {
    case '1':
    {
        cout << "现在系统当中共有歌单" << musicList::getListNumber() << endl;
        Print_All_the_List(The_list_of_musicList);
    }
    break;
    case '2':
    {
        cout << "请输入您希望进行标记的歌单索引" << endl;
        int j;
        cin >> j;

        musicList &M = The_list_of_musicList[j];

        cout << "请输入你喜欢的歌曲,输入-1退出" << endl;
        int index;
        while (cin >> index)
        {
            if (index == -1)
                break;
            M.musiclist[index - 1].is_liked();
            LM.Add_Music(M.musiclist[index - 1]);
        }
    }
    break;
    case '3':
    {
        if (LM.Music_number_in_this_list() == 0)
        {
            cout << "没有喜欢的歌曲" << endl;
            break;
        }
        LM.PrintMusiclist();
    }
    break;
    case '4':
    {
        cout << "请输入您希望进行合并的两个歌单的索引" << endl;
        int i, j;
        cin >> i >> j;
        musicList M = The_list_of_musicList[i] + The_list_of_musicList[j];

        cout << "请您数新歌单的名字" << endl;
        string new_name;
        cin >> new_name;
        M.Reset_ListName(new_name);

        The_list_of_musicList.push_back(M);
        int new_index = The_list_of_musicList.size() - 1;
        cout << "歌单已经合并成功,新的歌单的索引是" << new_index << endl;
    }
    break;
    case '5':
    {
        cout << "请输入您希望进行操作的歌单索引" << endl;
        int index;
        cin >> index;
        while (index >= The_list_of_musicList.size())
        {
            cout << "索引过大，请重新输入" << endl;
            cin >> index;
        }
        The_list_of_musicList[index].Operate_the_List();
    }
    break;
    case '6':
    {
        LM.Operate_the_List();
    }
    break;
    case '7':
    {
        cout << "请输入歌手的名字" << endl;
        string name;
        cin >> name;
        cout << "请输入歌手的性别" << endl;
        string sex;
        cin >> sex;
        cout << "请输入歌手的年龄" << endl;
        int age;
        cin >> age;
        Favour_anthor F(name, sex, age, The_list_of_musicList, LM);
    }
    break;
    case '8':
    {
        Operate_The_author(set_of_anthor, The_list_of_musicList, LM);
    }
    break;
    case '9':
    {
        cout << "现在程序中一共有歌曲" << music::Music_number() << "首" << endl;
    }
    case 'o':
    {
        WinExec("./player.exe", SW_SHOW);
    }
    break;
    }
}

int main()
{
    controller ctl;
    LikeMusicList LM;
    vector<Favour_anthor> set_of_anthor;
    vector<musicList> The_list_of_musicList;

    ctl.welcome();
    // 初始化控制器类
    ctl.init(LM, set_of_anthor, The_list_of_musicList);
    // 初始化播放列表
    char mode = ctl.menu();
    while (mode != 'q')
    {
        ctl.selection(mode, LM, set_of_anthor, The_list_of_musicList);
        mode = ctl.menu();
    }

    cout << "欢迎再次使用!" << endl;

    return 0;
}
