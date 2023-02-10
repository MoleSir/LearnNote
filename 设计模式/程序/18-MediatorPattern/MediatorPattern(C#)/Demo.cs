/* C# 实现中介者模式 */
using System;

namespace MediatorPatternApp
{
    public class ChatRoom
    {
        public static void ShowMessage(User user, string message)
        {
            Console.WriteLine("[{0}]: {1}", user.Name, message);
        }
    }

    public class User
    {
        public string Name
        {
            get
            {
                return this.name;
            }
            set
            {
                this.name = value;
            }
        }
        public User(string name)
        {
            this.name = name;
        }
        public void SendMessage(string message)
        {
            ChatRoom.ShowMessage(this, message);
        }
        private string name;
    }
    
    class Program
    {
        static void Main()
        {
            User u1 = new User("Yechen");
            User u2 = new User("Xuyuting");

            u1.SendMessage("Are you free?");
            u2.SendMessage("Yes, go to play!");
        }
    }
}