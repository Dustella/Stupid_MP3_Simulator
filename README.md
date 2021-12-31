# 音乐播放管理仿真系统-课程设计报告

## 1 系统分析

### 1.1 系统功能介绍

* 模拟播放音乐状态，切换播放状态；

* 多个自定义播放列表的存储和修改，以json格式存储于硬盘；

* 歌曲添加和修改；

### 1.2 系统类图

【参考 播放器 B 类图.pdf 画一下】

其中：playList 将vector\<music\>作为playList类中的数据成员存放数据；playList派生出了nowPlayinglist,添加正在播放曲目的索引；

playListControl需要控制所有的播放列表，因此添加数据成员store来实现部分数据绑定，同时添加若干与用户交互的函数进行播放列表操作；而player需要切换下一首、循环方式切换等功能，除了实现相对应的函数，也将一个nowPlayingList对象作为其数据成员进行操作，并使用几个数据成员存储播放状态。

之后，playContrl类作为主菜单，实现了最开始若干与用户交互的函数，有一个store对象存储所有播放列表数据，并且和磁盘上的播放列表瓦全同步。playControl是我们的入口点。

## 2 系统设计

### 2.1 系统总体结构

【参考 播放器 B 设计结构.pdf 画一下】

playList派生出了nowPlayinglist,添加正在播放曲目的索引；

playListControl作为各大playList的控制器，实现对不同播放列表的控制，而player作为nowPlayingList的控制器，实现切换下一首、循环方式切换等功能。

之后，playContrl类作为主菜单，实例化两大控制器，并实例化store类实现和磁盘上的播放列表数据绑定。最终，我们主函数只需要实例化playControl即可

### 2.2 系统文件结构

    ./
    │  main.cpp
    │  README.md
    │  store.json
    │
    ├─controller
    │      playControl.cpp
    │      playControl.h
    │      playlistControl.cpp
    │      playlistControl.h
    │
    ├─music
    │      music.cpp
    │      music.h
    │      Player.cpp
    │      Player.h
    │
    ├─playLists
    │      favMusicList.cpp
    │      favMusicList.h
    │      List.h
    │      nowPlayinglist.cpp
    │      nowPlayinglist.h
    │      playList.cpp
    │      playList.h
    │
    ├─store
    │      store.cpp
    │      store.h
    │
    └─utils
            cJSON.c
            cJSON.h
            CJsonObject.cpp
            CJsonObject.hpp

其中，存储播放列表的【store.json】使用如下的 json 格式

    {
        "nowPlayinglist": [{
                "Title": "Enchantress",
                "Album": "Vanquish",
                "Author": "Thomas Bergersen"
            }, {
                "Title": "Vanquish",
                "Album": "Vanquish",
                "Author": "Thomas Bergersen"
            }],
        "MyFav": [{
            }],
        "lalala": [],

## 3 系统实现

### 3.1 系统开发环境

整个项目在

* Manjaro Linux 下开发并测试

* 使用 gcc 11.1.0 作为编译器

* Microsoft Visual Studio Code 1.16.3 作为集成开发环境，

* vscode-cpptools 规范代码风格。

### 3.2 系统开发过程

首先，我们设计了底层类music和播放列表playlist，使用STL动态存储播放列表中多个music的数据状态。

此处给出music.h中部分内容：

``` C++
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
```


给出playList.h的部分内容：

```C++
private:
    int totalMusicNum = 0; //记录这个歌单中歌曲的数量
    string playListName;   //歌单的名字

public:
    vector<music> musiclist;        //存放歌曲
    playlist(const playlist &list); //复制构造函数
    playlist(){};
    playlist(string playListName, vector<music> Mlist);

    bool append(music M);          //增加歌曲
    void insert(int pos, music M); //
    bool pop(string music_name);   //删除歌曲
    int length();                  //得到长度
    void updateLength();
    void swap(int a, int b);

    void setListName(string a);
    string getListName() const; // 显示播放列表名字
    string getFormattedList();  //显示这个歌单中所有歌曲的名字

    void setPlaylist(playlist ls);

    vector<music> searchByAuthor(string author_name);
    vector<music> searchByTitle(string name);

    music operator[](int i)
    {
        return musiclist[i];
    }
```

之后制作player类来提供逻辑上的播放列表操作（下一首，暂停，继续等等）

给出 player.h 部分内容：

```C++
public:
	void setPlaybackState(string mode);
	void play();
	void pause();
	void nextPlay();
	void previousPlay();

	string playingInfo();

	Player(playlist M);
	Player();

	void setPlaylist(playlist L);

private:
	bool isPaused = true;
	string playbackState = "loop";
	nowPlayinglist nowPlaying;
```

然后我们需要考虑播放列表和音乐存储的问题。【由于不让用多文件和数据库 <= 这句话别写进报告里】容易想到使用json格式操作存储。由于C++不是JavaScript，不能直接处理json格式的数据或者操作json对象，于是，我们调用了CJson库，并单独设计一个store类，给播放列表提供存储支持。

在store类中，我们建立私有对象CJsonObject data作为在活动内存中存在的数据，并设计syncPlayls()方法，使用fstream流将Json对象写入硬盘上的store.json

此处给出实现读取数据的关键代码

```C++
void store::syncPlaylist(playlist ls)
{
    string name = ls.getListName();
    cout << name << endl;
    if (data.GetKey(name))
    {
        cout << "is" << endl;

        data.AddEmptySubArray(ls.getListName());
    }
    for (int i = 0; i < ls.length(); i++)
    {
        music tmp = ls[i];
        CJsonObject musicObject;
        musicObject.Add("Title", tmp.getTitle());
        musicObject.Add("Album", tmp.getAlbum());
        musicObject.Add("path", tmp.getPath());
        musicObject.Add("Author", tmp.getAuthor());
        data[ls.getListName()].Add(musicObject);
    }
    writeStore();
}

vector<playlist> store::getAllPlaylists()
{
    vector<playlist> result;

    string playlistName;
    CJsonObject playlistObject;
    while (data.GetKey(playlistName))
    {
        if (data.Get(playlistName, playlistObject))
        {
            playlist tmp;
            tmp.setListName(playlistName);
            for (int i = 0; i < data[playlistName].GetArraySize(); i++)
            {
                string Title;
                data[playlistName][i].Get("Title", Title);

                string Album;
                data[playlistName][i].Get("Album", Album);

                string Author;
                data[playlistName][i].Get("Author", Author);

                string path;
                data[playlistName][i].Get("Path", path);

                music toAdd(Title, Author, Album, path);

                tmp.append(toAdd);
            }
            result.push_back(tmp);
        }
    }

    return result;
}
```

最后我们设计给用户提供交互的类，我们设计了playlistControl 和 playControl 类，实例化上面的类，绑定播放列表存储，然后提供给用户交互。

最后，在 main.cpp 中，我们实例化playControl类，就完成了整个系统设计

main.cpp
```C++
#include "controller/playControl.cpp"

int main()
{
    playControl ctl;
    return 0;
}
```

## 4 系统运行示例

由于CJson的问题，需要在Linux下编译运行。

【图已经补全】

![20211231125713](https://dustella-markdown-imgs.oss-cn-shanghai.aliyuncs.com/images/20211231125713.png)

图 主菜单界面

![20211231125727](https://dustella-markdown-imgs.oss-cn-shanghai.aliyuncs.com/images/20211231125727.png)

图 播放列表控制面板

![20211231125813](https://dustella-markdown-imgs.oss-cn-shanghai.aliyuncs.com/images/20211231125813.png)

图 向新建的播放列表中添加歌曲

![20211231125834](https://dustella-markdown-imgs.oss-cn-shanghai.aliyuncs.com/images/20211231125834.png)

图 播放列表选择界面

![20211231130041](https://dustella-markdown-imgs.oss-cn-shanghai.aliyuncs.com/images/20211231130041.png)

图 播放列表管理歌曲界面

## 5 总结与体会

为了保证【高内聚，低耦合】，我们在最开始设计系统的时候就花了非常大的努力去让所有的模块尽可能松散，保证所有模块只依赖下一层类而不会乱用别的模块，并成功让最终复杂的依赖关系只发生在最后的controller中。  

最终，我们是相对成功的。我们的确降低了代码耦合度，模块之间的确非常松散。但是造成另一个问题，过度封装。

对于playlist类而言，我们确实只是给原有的STL类的方法再包装了一层，然后给出了一个播放列表名字和对应的getter setter。 这确实是累赘的，虽然播放列表还派生了正在播放列表和喜欢播放列表需要一个基类，但是确实不需要额外写一整套播放列表，一个vector是足够了。

我们为了节约时间，读取数据部分，我们使用了现成的数据结构JSON，没有自己设计存储的数据结构。同时，我们设计的数据结构非常简单，数据复用率非常低，导致占用较多存储空间。

在编码过程中，我们对C++各模块之间的引用有了更深的理解。

我们在制作模拟之前遇到了大量别的困难。

我们最开始尝试不用仿真，而使用qt6和QMedia组件制作播放器。但是我们浪费了大量时间阅读qt6和QMedia的文档，接触了大量qt开发的内容。由于qt6中多媒体部分大改，而现有大量资料都是qt5的，我们依靠有限的官方文档只实现了最基础的音乐播放，完全没有能力实现播放列表和列表的图形化。  
更可怕的是，我们使用了过多qt提供的第三方库.QString 、QAbstract QUrl Qdir代替了原生C++中的string， stl， fstream等。我们意识到我们使用了过多第三方库中的内容，与最开始想要的开发有太大差距。最后，qml没有html那么好调试，我们很难做出优美的图形界面。最后，我们选择放弃qt方案而开发了这套仿真系统。

## 参考文献

[1] [Bwar的CJson库](https://github.com/Bwar/CJsonObject)

| 小组编号        | 组长   | 组长学号     |
| --------------- | ------ | ------------ |
| 腾讯班第 2 组 | 余翰文 | 202013170029 |

| 学号         | 姓名   | 具体分工 |
| ------------ | ------ | -------- |
| 202013170029 | 余翰文 | 系统主要结构设计 播放器和数据设计、交互设计 |
| 202013260034 | 赵建桥 | 播放列表、音乐类设计、交互设计 |
| 202083250012 | 陈慧琳 | 播放列表、音乐类设计、实验报告撰写 |

## 附录

整个项目的所有代码和报告已经托管至 

https://gitlab.dustella.net/Dustella/music_player_cpp_B 

这里是我们已经放弃的qt版本的播放器

https://gitlab.dustella.net/Dustella/simple_player