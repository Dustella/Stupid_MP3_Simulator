#ifndef MUSIC_H
#define MUSIC_H
#include <string>
using namespace std;
class musicList;

class music
{
    friend bool operator<(const music &, const music &);
    friend bool operator>(const music &, const music &);
    friend bool operator<=(const music &, const music &);
    friend class musicList;
    friend bool operator==(music &m1, music &m2); //比较作者和歌曲名
public:
    // music(){};w
    music(string N, string A, string f);
    //  music(string N,string A,string filename);
    // music(string N,string A,string filename,FILE* f=nullptr);
    // music(string N,string A,string filename,string path,FILE* f=nullptr);
    //  inline string showname() const;//չʾ��������
    //  inline string showauthor() const;//չʾ����������
    string getName() const;    // 显示名字
    string getAuther() const;  // 得到作者名字
    static int Music_number(); // 得到音乐序号
    void liked();              //切换喜欢
    void setInfo();
    void play();              //得到
    string getPath();          // 返回路径
    bool is_liked();
    ~music();

private:
    string filename;
    string name;                // 歌曲名字
    string author;              // 作者
    bool is_like = false;       //标记歌曲是否被喜欢
    static int number;          // 音乐序号
    string music_file = ""; // 音乐位置
    string path;
};

#endif
