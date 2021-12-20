#ifndef MUSIC_H
#define MUSIC_H
#include<string>
using namespace std;
class musicList;
class music
{
    friend bool operator <(const music&, const music&);
    friend bool operator >(const music&, const music&);
    friend bool operator <=(const music&,const music&);
    friend class musicList;
    friend bool operator == (music &m1, music &m2);//�ж����������Ƿ���ͬ���ں���ʵ�ָ赥�ĺϲ���ʱ��ʹ��
public:
    // music(){};
    music(string N,string A,FILE* f= nullptr);
//  music(string N,string A,string filename);
    // music(string N,string A,string filename,FILE* f=nullptr);
    // music(string N,string A,string filename,string path,FILE* f=nullptr);
//  inline string showname() const;//չʾ��������
//  inline string showauthor() const;//չʾ����������
    string showname() const;//չʾ��������
    string showauthor() const;//չʾ��
    static int Music_number();//��ʾ���ȥ���и�������
    void liked();//��������Ϊϲ���ĸ�������ȡ��ϲ��
    FILE* play();//���ʸ����ļ��Ľӿ�
    string Play(); 
    bool is_liked();
    ~music();
private:
    string filename;
    string name;//����������
    string author;//��������
    bool is_like=false;//�Ƿ���ϲ���ĸ���
    static int number;//��������
    FILE * music_file= nullptr;//���ڶ�ȡ�����ļ�
    string path;
};

#endif
