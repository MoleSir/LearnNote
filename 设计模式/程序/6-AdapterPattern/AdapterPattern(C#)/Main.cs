/* C# 实现适配器模式 */
using System;

namespace AdapterPattern
{
    public interface MediaPlayer
    {
        void play(string audioType, string fileName);
    }

    public interface AdvanceMediaPlayer
    {
        void playVlc(string fileName);
        void playMp4(string fileName);
    }

    public class VlcPlayer: AdvanceMediaPlayer
    {
        public void playVlc(string fileName)
        {
            Console.WriteLine("Playing vlc file, Name: " + fileName);
        }
        public void playMp4(string fileName)
        {
        }
    }

    public class Mp4Player: AdvanceMediaPlayer
    {
        public void playVlc(string fileName)
        {
        }
        public void playMp4(string fileName)
        {
            Console.WriteLine("Playing mp4 file, Name: " + fileName);
        }
    }

    public class MediaAdapter: MediaPlayer
    {
        public MediaAdapter(string audioType)
        {
            if (audioType == "vlc")
                advanceMediaPlayer = new VlcPlayer();
            else if (audioType == "mp4")
                advanceMediaPlayer = new Mp4Player();
        }
        public void play(string audioType, string fileName)
        {
            if (audioType == "vlc")
                advanceMediaPlayer.playVlc(fileName);
            else if (audioType == "mp4")
                advanceMediaPlayer.playMp4(fileName);
        }

        private AdvanceMediaPlayer advanceMediaPlayer;
    }

    public class AudioPlayer: MediaPlayer
    {
        public void play(string audioType, string fileName)
        {
            if (audioType == "mp3")
                Console.WriteLine("Playing mp3 file. Name " + fileName);
            else if (audioType == "mp4" || audioType == "vlc")
            {
                mediaAdapter = new MediaAdapter(audioType);
                mediaAdapter.play(audioType, fileName);
            }
            else
                Console.WriteLine("Invalid media. "+ audioType + " format not supported");

        }
        private MediaAdapter mediaAdapter;
    }

    class Program
    {
        static void Main(string[] args)
        {
            AudioPlayer audioPlayer = new AudioPlayer();
        
            audioPlayer.play("mp3", "beyond the horizon.mp3");
            audioPlayer.play("mp4", "alone.mp4");
            audioPlayer.play("vlc", "far far away.vlc");
            audioPlayer.play("avi", "mind me.avi");
        }
    }
}