#ifndef MUSIC_H
#define MUSIC_H
#include <string>
using namespace std;
class playlist;

class music
{

    friend class playlist;
#pragma region operatorOverride
    friend bool operator<(const music &, const music &);
    friend bool operator>(const music &, const music &);
    friend bool operator<=(const music &, const music &);
    friend bool operator==(music &m1, music &m2); //比较作者和歌曲名
#pragma endregion operatorOverride

public:
    music(string N, string A, string K, string f);
    music();

    //  getter and setters
    string getAlbum() const;
    string getTitle() const;   // 显示名字
    string getAuthor() const; // 得到作者名字
    string getPath() const;         // 返回路径
    bool isLiked() const; //
    void setInfo(string title, string author, string album, string path);
    void setTitle(string name);
    void setPath(string path);
    void setAuthor(string author);
    void setAlbum(string album);
    void setLiked();
    void setUnliked();

    string constuctInfo();
    //   getter and setters

private:
    string Title;  // 歌曲名字
    string Author; // 作者
    string Album;
    string path = ""; // 音乐位置
    bool Liked; //
};

#endif
