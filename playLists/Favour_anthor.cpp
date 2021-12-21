#include "Favour_anthor.h"
#include "music.h"
#include "LikeMusicList.h"
#include <algorithm>

using namespace std;

void Favour_anthor::Operate_The_author(vector<Favour_anthor> &s, vector<musicList> &m, LikeMusicList &lm)
{
	Refresh(m, lm);
	cout << "请输入您希望进行的操作" << endl;
	cout << "展示歌曲输入1" << endl;
	cout << "展示个人信息输入2" << endl;
	cout << "筛选歌手" << endl;
	cout << "退出输入0" << endl;
	int choose;
	cin >> choose;
	while (choose)
	{
		if (choose == 1)
		{
			showMusic();
		}
		if (choose == 2)
		{
			cout << "姓名:" << showName() << endl;
			cout << "性别：" << showSex() << endl;
			cout << "年龄：" << showAge() << endl;
		}
		if (choose == 3)
		{
			cout << "请输入您希望进行筛选的信息" << endl;
			cout << "姓名输入1" << endl;
			;
			cout << "性别输入2" << endl;
			cout << "年龄输入3" << endl;
			int select;
			cin >> select;
			switch (select)
			{
			case 1:
			{
				cout << "请输入筛选歌手的姓名" << endl;
				string name;
				cin >> name;
				int flag = 0;
				for (auto e : s)
				{
					if (e.showName() == name)
					{
						cout << e.showName() << " " << e.showSex() << e.showAge() << endl;
						flag = 1;
					}
				}
				if (flag)
				{
					cout << "筛选成功" << endl;
				}
			}
			break;
			case 2:
			{
				cout << "请输入性别" << endl;
				string sex;
				cin >> sex;
				int flag = 0;
				for (auto e : s)
				{
					if (e.showSex() == sex)
					{
						cout << e.showName() << " " << e.showSex() << e.showAge() << endl;
						flag = 1;
					}
				}
				if (flag)
				{
					cout << "筛选成功" << endl;
				}
			}
			break;
			case 3:
			{
				cout << "请输入年龄" << endl;
				int age;
				cin >> age;
				int flag = 0;
				for (auto e : s)
				{
					if (e.showAge() == age)
					{
						cout << e.showName() << " " << e.showSex() << e.showAge() << endl;
						flag = 1;
					}
				}
				if (flag)
				{
					cout << "筛选成功" << endl;
				}
			}
			break;
			}
		}
	}
}

Favour_anthor::Favour_anthor(string name, string sex, int age, vector<musicList> &M, LikeMusicList &LM) : name(name), sex(sex), age(age)
{
	for (auto e : M)
	{
		for (auto Music : e.musiclist)
		{
			string MN = Music.getName();
			int flag = 1;
			for (int i = 0; i < music_name.size(); i++)
			{
				if (music_name[i] == MN)
				{
					flag = 0;
				}
			}

			if (flag)
			{
				music_name.push_back(MN);
				music *p;
				p = &Music;
				The_Music_of_the_anthor.push_back(p);
			}
		}
	}
	for (auto Music : LM.musiclist)
	{
		if (Music.getAuther() == name)
		{
			string MN = Music.getName();
			int flag = 1;
			for (int i = 0; i < music_name.size(); i++)
			{
				if (music_name[i] == MN)
				{
					flag = 0;
				}
			}

			if (flag)
			{
				music_name.push_back(MN);
				music *p;
				p = &Music;
				The_Music_of_the_anthor.push_back(p);
			}
		}
	}

	cout << "�Ƿ���λ���ֵ����и�������Ϊϲ������y/n��:";
	char choos;
	cin >> choos;
	if (choos == 'y')
	{
		for (auto e : The_Music_of_the_anthor)
		{
			if (!e->is_liked())
			{
				e->liked();
				if (LM.search_music(e->getName()) == false)
				{
					LM.Add_Music(*e);
				}
			}
		}
	}
}
int Favour_anthor::showAge()
{
	return age;
}

string Favour_anthor::showSex()
{
	return sex;
}

string Favour_anthor::showName()
{
	return name;
}

void Favour_anthor::Refresh(vector<musicList> &M, LikeMusicList &LM)
{
	for (auto e : M)
	{
		for (auto Music : e.musiclist)
		{
			string MN = Music.getName();
			int flag = 1;
			for (int i = 0; i < music_name.size(); i++)
			{
				if (music_name[i] == MN)
				{
					flag = 0;
				}
			}

			if (flag)
			{
				music_name.push_back(MN);
				music *p;
				p = &Music;
				The_Music_of_the_anthor.push_back(p);
			}
		}
	}
	for (auto Music : LM.musiclist)
	{
		if (Music.getAuther() == name)
		{
			string MN = Music.getName();
			int flag = 1;
			for (int i = 0; i < music_name.size(); i++)
			{
				if (music_name[i] == MN)
				{
					flag = 0;
				}
			}

			if (flag)
			{
				music_name.push_back(MN);
				music *p;
				p = &Music;
				The_Music_of_the_anthor.push_back(p);
			}
		}
	}
}

bool operator==(Favour_anthor a, Favour_anthor b)
{
	if (a.name == b.name && a.age == b.age && a.sex == b.sex)
	{
		return true;
	}
	else
		return false;
}

void Favour_anthor::showMusic()
{
	int i = 0;
	cout << "��������" << The_Music_of_the_anthor.size() << endl;
	for (auto e : The_Music_of_the_anthor)
	{
		cout.width(5);
		cout << i << " ";
		cout.width(40);
		cout << e->getName() << endl;
	}
}

void Favour_anthor::sort_by_name(int low, int high)
{
	if (low < high)
	{
		int i = low, j = high;
		string x = music_name[low];
		music *X = The_Music_of_the_anthor[i];
		while (i < j)
		{
			while (i < j && music_name[j] > x)
				j--;
			if (i < j)
			{
				The_Music_of_the_anthor[i] = The_Music_of_the_anthor[j];
				music_name[i++] = music_name[j];
			}
			while (i < j && music_name[i] <= x)
				i++;
			if (i < j)
			{
				The_Music_of_the_anthor[j] = The_Music_of_the_anthor[i];
				music_name[j--] = music_name[i];
			}
		}
		music_name[i] = x;
		The_Music_of_the_anthor[i] = X;
		sort_by_name(low, i - 1);
		sort_by_name(i + 1, high);
	}
}
