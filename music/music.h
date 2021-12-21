#ifndef MUSIC_H
#define MUSIC_H
#include <string>
using namespace std;
class musicList;

class music
{

#pragma region operatorOverride
    friend bool operator<(const music &, const music &);
    friend bool operator>(const music &, const music &);
    friend bool operator<=(const music &, const music &);
    friend class musicList;
    friend bool operator==(music &m1, music &m2); //比较作者和歌曲名
#pragma endregion operatorOverride

public:
    music(string N, string A, string K, string f);
    string getAlbum() const;
    string getTitle() const;   // 显示名字
    string getAuthor() const; // 得到作者名字
    string getPath() const;         // 返回路径
    void setInfo(string title, string author, string album, string path);
    void setTitle(string name);
    void setPath(string path);
    void setAuthor(string author);
    void setAlbum(string album);

private:
    string Title;  // 歌曲名字
    string Author; // 作者
    string Album;
    string path = ""; // 音乐位置
};

#endif
