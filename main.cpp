#include <iostream>
#include "music.cpp"
#include "musicList.cpp"
#include "LikeMusicList.cpp"
#include "Favour_anthor.cpp"
#include <vector>
#include <string.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

//����unixϵͳ��
// #include <sys/types.h>
// #include <dirent.h>

// void getFiles(string path, vector<string>& filenames)
// {
//     DIR *pDir;
//     struct dirent* ptr;
//     if(!(pDir = opendir(path.c_str()))){
//         cout<<"Folder doesn't Exist!"<<endl;
//         return;
//     }
//     while((ptr = readdir(pDir))!=0) {
//         if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0){
//             filenames.push_back(path + "/" + ptr->d_name);
//         }
//     }
//     closedir(pDir);
// }

// ��windowsϵͳ��
#include <io.h>

void getFiles(string path, vector<string> &files)
{
    //�ļ����
    long hFile = 0;
    //�ļ���Ϣ������һ���洢�ļ���Ϣ�Ľṹ��
    struct _finddata_t fileinfo;
    string p;                                                                        //�ַ��������·��
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) //�����ҳɹ��������
    {
        do
        {
            //�����Ŀ¼,����֮�����ļ����ڻ����ļ��У�
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                //�ļ���������"."&&�ļ���������".."
                //.��ʾ��ǰĿ¼
                //..��ʾ��ǰĿ¼�ĸ�Ŀ¼
                //�ж�ʱ�����߶�Ҫ���ԣ���Ȼ�����޵ݹ�������ȥ�ˣ�
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            //�������,�����б�
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose������������
        _findclose(hFile);
    }
}

void CreateList(string path, string name, musicList *M)
{
    M->list_name = name;

    vector<string> filename;
    getFiles(path, filename);
    M->music_number = filename.size();
    for (auto e : filename)
    {
        string music_name;
        int i = 0;
        while (e[i] != '-')
        {
            music_name[i] = e[i];
            i++;
        }
        i++;
        string author;
        while (e[i] != '.')
        {
            author[i] = e[i];
            i++;
        }
        music Mu(music_name, author, nullptr);
    }
    M->sort_by_name(0, M->musiclist.size() - 1);
}

void Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm)
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

void Print_All_the_List(const vector<musicList> &The_lists)
{
    for (auto M : The_lists)
    {
        cout.width(30);
        cout << M.showListName();
        cout << endl;
        M.PrintMusiclist();
    }
}

int main()
{
    LikeMusicList LM;
    cout << "=====================��ӭʹ�����ֹ���ϵͳ===================" << endl;
    vector<Favour_anthor> set_of_anthor;
    vector<musicList> The_list_of_musicList;
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
        if (judge.size() == 2)
        {
            cout << "������赥������" << endl;
            cin >> name;
        }
        musicList M;
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

    char flag;
    cout << "�鿴�������и赥�������������1" << endl;
    cout << "���ϲ���ĸ���������2" << endl;
    cout << "�鿴ϲ���ĸ���������3" << endl;
    cout << "�ϲ��赥������4" << endl;
    cout << "�����ض��赥���в���������5" << endl;
    cout << "����ϲ���ĸ���������6" << endl;
    cout << "����ϲ���ĸ���������7" << endl;
    cout << "�Ը��ֽ��в�������8" << endl;
    cout << "�鿴���и�����Ŀ������9" << endl;
    cout << "�˳�����'q" << endl;
    while (flag != 'q')
    {

        cin >> flag;
        switch (flag)
        {
        case '1':
        {
            cout << "����ϵͳ���й��и赥" << musicList::List_number() << endl;
            Print_All_the_List(The_list_of_musicList);
        }
        break;
        case '2':
        {
            cout << "��������ϣ�����б�ǵĸ赥����" << endl;
            int j;
            cin >> j;

            musicList &M = The_list_of_musicList[j];

            cout << "��������ϲ���ĸ���,����-1�˳�" << endl;
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
                cout << "û��ϲ���ĸ���" << endl;
                break;
            }
            LM.PrintMusiclist();
        }
        break;
        case '4':
        {
            cout << "��������ϣ�����кϲ��������赥������" << endl;
            int i, j;
            cin >> i >> j;
            musicList M = The_list_of_musicList[i] + The_list_of_musicList[j];

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
        break;
        }
    }

    cout << "��ӭ�ٴ�ʹ��!" << endl;

    return 0;
}
