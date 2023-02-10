#ifndef __ADAPTER_PATTERN_H__
#define __ADAPTER_PATTERN_H__

/* 适配器模式头文件 */
#include <iostream>
#include <string>


namespace AdapterPattern
{
    /* 为媒体播放器和更高级的媒体播放器创建接口 ***************************************/
    class MediaPlayer
    {
    public:
        virtual void play(const std::string& audioType, const std::string& fileName) = 0;
    };

    class AdvancedMediaPlayer
    {
    public:
        virtual void playVlc(const std::string& fileName) = 0;
        virtual void playMp4(const std::string& fileName) = 0;
    };


    /* 创建实现了 AdvancedMediaPlayer 接口的实体类 ************************************/
    class VlcPlayer: public AdvancedMediaPlayer
    {
    public:
        virtual void playVlc(const std::string& fileName) override;
        virtual void playMp4(const std::string& fileName) override;
    };

    class Mp4Player: public AdvancedMediaPlayer
    {
    public:
        virtual void playVlc(const std::string& fileName) override;
        virtual void playMp4(const std::string& fileName) override;
    };


    /* 创建实现了 MediaPlayer 接口的适配器类 *******************************************/
    class MediaAdapter: public MediaPlayer
    {
    public:
        // 通过指定哪种高级播放器为适配器构造
        MediaAdapter(const std::string& audioType); 
        // 析构函数，用于释放堆对象
        ~MediaAdapter();
        // 对外暴露出接口，其实内部只是 advancedMediaPlayer 起作用，可以看出这个接口与 MediaPlayer 一致
        virtual void play(const std::string& audioType, const std::string& fileName) override;
    private:
        // 使用一个 AdvancedMediaPlayer 来实现播放功能
        AdvancedMediaPlayer* advancedMediaPlayer;
    };


    /* 创建实现了 MediaPlayer 接口的实体类 *********************************************/
    class AudioPlayer: public MediaPlayer
    {
    public:
        // 实现 play
        virtual void play(const std::string& audioType, const std::string& fileName) override;
    private:
        // 使用一个播放器适配器来实现多种播放功能
        MediaAdapter* mediaAdapter = nullptr;
    };
}

#endif