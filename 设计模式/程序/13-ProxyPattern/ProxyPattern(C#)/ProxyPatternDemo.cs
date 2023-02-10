/* C#实现代理模式 */
using System;

namespace ProxyPattern
{   
    /* 接口 */
    public interface Image
    {
        void display();
    }

    /* 实现 */
    public class RealImage : Image
    {
        public RealImage(string fileName)
        {
            this.fileName = fileName;
        }
        public void display()
        {
            Console.WriteLine("Load file: {0}", this.fileName);
        }

        private string fileName;
    }

    public class ProxyImage : Image
    {
        public ProxyImage(string fileName) 
        {
            this.fileName = fileName;
            this.realImage = null;
        }
        public void display()
        {
            if (this.realImage == null)
            {
                Console.WriteLine("Load from disk!");
                this.realImage = new RealImage(this.fileName);
            }
            this.realImage.display();
        }

        private string fileName;
        private RealImage realImage;
    }

    public class Program
    {
        static void Main(string[] args)
        {
            Image image = new ProxyImage("test_proxy.png");

            image.display();
            image.display();
        }
    }
}