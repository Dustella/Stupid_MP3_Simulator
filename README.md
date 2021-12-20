# 音乐播放管理系统-课程设计报告

成员

赵建桥 余翰文 陈慧琳

## 1 系统分析

### 1.1 系统功能介绍

播放音乐、存储；

播放列表的存储；

切换播放状态；

### 1.2 系统类图

        string getName() const;    // 显示名字
        string getAuther() const;  // 得到作者名字
        static int Music_number(); // 得到音乐序号
        void liked();              //切换喜欢
        FILE *play();              //得到
        string getPath();          // 返回路径
        bool is_liked();
        ~music();

    private:
        string filename;
        string name;                // 歌曲名字
        string author;              // 作者
        bool is_like = false;       //标记歌曲是否被喜欢
        static int number;          // 音乐序号
        FILE *music_file = nullptr; // 音乐位置
        string path;

## 2 系统设计

### 2.1 系统总体结构

### 2.2 系统文件结构

## 3 系统实现

### 3.1 系统开发环境

### 3.2 系统开发过程

## 4 系统运行示例

## 5 总结与体会

## 参考文献

