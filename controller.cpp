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
    //�ļ���Ϣ������һ���洢�ļ���Ϣ�Ľṹ��
    struct _finddata_t fileinfo;
    string p;                                                                         //�ַ��������·��
    if ((hFile = _findfirst(p.assign(ORING).append("\\*").c_str(), &fileinfo)) != -1) //�����ҳɹ��������
    {
        do
        {
            //�����Ŀ¼,����֮�����ļ����ڻ����ļ��У�
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                //�ļ���������"."&&�ļ���������".."
                //�ж�ʱ�����߶�Ҫ���ԣ���Ȼ�����޵ݹ�������ȥ�ˣ�
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(ORING).append("\\").append(fileinfo.name), files);
            }
            //�������,�����б�
            else
            {
                files.push_back(p.assign(ORING).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose������������
        _findclose(hFile);
    }
}

void controller::CreateList(string ORING, string name, playlist *M)
{
    cout << ORING << " " << name << endl;
    cout << "CreatingList" << endl;
    // M->setListName(name);
    vector<string> path;

    readConfig(ORING, path);
    if (path.size() == 0)
    {
        string s1 = "D:\\music\\��·-����.mp3";
        path.push_back(s1);
    }
    // M->setListNumber(path.size());
    cout << path.size() << endl;
    for (auto e : path)
    {

        string music_name = "��·";
        string author = "����";
        music Mu(music_name, author, e);
    }
    M->sort_by_name(0, M->musiclist.size() - 1);
}

void controller::Operate_The_author(vector<Favour_anthor> &s, vector<playlist> &m, LikeMusicList &lm)
{
    cout << "��������ϣ�����в����ĸ��ֵ�����" << endl;
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
        cout << "�����������������������" << endl;
        cin >> index;
    }
    (s[index]).Operate_The_author(s, m, lm);
}

void controller::Print_All_the_List(const vector<playlist> &The_lists)
{
    for (auto M : The_lists)
    {
        cout.width(30);
        cout << M.showListName();
        cout << endl;
        M.getFormattedList();
    }
}

char controller::menu()
{
    char f;
    cout << "�鿴�������и赥�������������1" << endl;
    cout << "���ϲ���ĸ���������2" << endl;
    cout << "�鿴ϲ���ĸ���������3" << endl;
    cout << "�ϲ��赥������4" << endl;
    cout << "�����ض��赥���в���������5" << endl;
    cout << "����ϲ���ĸ���������6" << endl;
    cout << "����ϲ���ĸ���������7" << endl;
    cout << "�Ը��ֽ��в�������8" << endl;
    cout << "�鿴���и�����Ŀ������9" << endl;
    cout << "�򿪲�����������������o" << endl;
    cout << "�˳�����'q" << endl;
    cin >> f;
    return f;
}

void controller::init(LikeMusicList &LM, vector<Favour_anthor> set_of_anthor, vector<playlist> The_list_of_musicList)
{ //��ʼ�������б�
    while (1)
    {

        cout << "������赥��·��" << endl;
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
        cout << "������赥������" << endl;
        cin >> name;
        // }

        playlist M;
        CreateList(path, name, &M);
        The_list_of_musicList.push_back(M);
        cout << "���Ƿ�ϣ�����������µĸ赥(y/n��:";
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
    cout << "=====================��ӭʹ�����ֹ���ϵͳ===================" << endl;
}
void controller::selection(char choice, LikeMusicList &LM, vector<Favour_anthor> &set_of_anthor, vector<playlist> &The_list_of_musicList)
{
    switch (choice)
    {
    case '1':
    {
        cout << "����ϵͳ���й��и赥" << playlist::getListNumber() << endl;
        Print_All_the_List(The_list_of_musicList);
    }
    break;
    case '2':
    {
        cout << "��������ϣ�����б�ǵĸ赥����" << endl;
        int j;
        cin >> j;

        playlist &M = The_list_of_musicList[j];

        cout << "��������ϲ���ĸ���,����-1�˳�" << endl;
        int index;
        while (cin >> index)
        {
            if (index == -1)
                break;
            M.musiclist[index - 1].is_liked();
            LM.append(M.musiclist[index - 1]);
        }
    }
    break;
    case '3':
    {
        if (LM.getNum() == 0)
        {
            cout << "û��ϲ���ĸ���" << endl;
            break;
        }
        LM.getFormattedList();
    }
    break;
    case '4':
    {
        cout << "��������ϣ�����кϲ��������赥������" << endl;
        int i, j;
        cin >> i >> j;
        playlist M = The_list_of_musicList[i] + The_list_of_musicList[j];

        cout << "�������¸赥������" << endl;
        string new_name;
        cin >> new_name;
        M.Reset_ListName(new_name);

        The_list_of_musicList.push_back(M);
        int new_index = The_list_of_musicList.size() - 1;
        cout << "�赥�Ѿ��ϲ��ɹ�,�µĸ赥��������" << new_index << endl;
    }
    break;
    case '5':
    {
        cout << "��������ϣ�����в����ĸ赥����" << endl;
        int index;
        cin >> index;
        while (index >= The_list_of_musicList.size())
        {
            cout << "������������������" << endl;
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
        cout << "��������ֵ�����" << endl;
        string name;
        cin >> name;
        cout << "��������ֵ��Ա�" << endl;
        string sex;
        cin >> sex;
        cout << "��������ֵ�����" << endl;
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
        cout << "���ڳ�����һ���и���" << music::Music_number() << "��" << endl;
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
    vector<playlist> The_list_of_musicList;

    ctl.welcome();
    // ��ʼ����������
    ctl.init(LM, set_of_anthor, The_list_of_musicList);
    // ��ʼ�������б�
    char mode = ctl.menu();
    while (mode != 'q')
    {
        ctl.selection(mode, LM, set_of_anthor, The_list_of_musicList);
        mode = ctl.menu();
    }

    cout << "��ӭ�ٴ�ʹ��!" << endl;

    return 0;
}
