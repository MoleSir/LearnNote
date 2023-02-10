#include "AdapterPattern.h"
using namespace AdapterPattern;

int main()
{
    AudioPlayer* audioPlayer = new AudioPlayer();

    audioPlayer->play("Mp3", "beyond the horizon.mp3");
    audioPlayer->play("Mp4", "alone.mp4");
    audioPlayer->play("Vlc", "far far away.vlc");
    audioPlayer->play("Avi", "mind me.avi");

    return 0;
}