#include "AdapterPattern.h"
#include <iostream>
#include <string>


namespace AdapterPattern
{
    void VlcPlayer::playVlc(const std::string& fileName)
    {
        // 播放 vlc 文件
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }

    void VlcPlayer::playMp4(const std::string& fileName)
    {
        // 什么也不做
    }

    void Mp4Player::playVlc(const std::string& fileName)
    {
        // 什么也不做
    }

    void Mp4Player::playMp4(const std::string& fileName)
    {
        // 播放 MP4 文件
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
 
    MediaAdapter::MediaAdapter(const std::string& audioType): advancedMediaPlayer(nullptr)
    {
        // 根据 audioType 创建不同的播放器
        if (audioType == "Vlc")
            this->advancedMediaPlayer = new VlcPlayer();
        else if (audioType == "Mp4")
            this->advancedMediaPlayer = new Mp4Player();
    }

    void MediaAdapter::play(const std::string& audioType, const std::string& fileName)
    {
        // 根据 audioType 播放不同类型的文件
        if (audioType == "Vlc")
            this->advancedMediaPlayer->playVlc(fileName);
        else if (audioType == "Mp4")
            this->advancedMediaPlayer->playMp4(fileName);
    }

    MediaAdapter::~MediaAdapter()
    {
        if (this->advancedMediaPlayer != nullptr)
            delete this->advancedMediaPlayer;
    }

    void AudioPlayer::play(const std::string& audioType, const std::string& fileName)
    {
        // 播放普通的 mp3
        if (audioType == "Mp3")
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        else if (audioType == "Vlc" || audioType == "Mp4")
        {
            if (mediaAdapter) delete mediaAdapter;
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        }
        else
            std::cout << "Invalid media. " << audioType << " format not supported" << std::endl;
    }
}