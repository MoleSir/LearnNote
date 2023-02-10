using System;
using System.Threading;
using System.Runtime.CompilerServices;

namespace SingletonPatternApp
{
    /* 懒汉式-线程不安全 */
    public class Singleton
    {
        // 私有构造函数
        private Singleton()
        {

        }   

        // 获取对象函数
        static public Singleton GetInstance()
        {
            if (Singleton.instance == null)
            {
                Singleton.instance = new Singleton();
            }
            else
            {
                Console.WriteLine("already have a Sington object!");
            }
            return Singleton.instance;
        }

        static private Singleton instance = null;
    }

    /* 懒汉式-线程安全 */
    class Singleton2
    {
        private Singleton2(){}
        private static Singleton2 instance = null;

        // 互斥方法
        [MethodImpl(MethodImplOptions.Synchronized)]
        public static Singleton2 GetInstance()
        {
            if (Singleton2.instance == null)
            {
                Singleton2.instance = new Singleton2();
            }
            else
            {
                Console.WriteLine("already have a Sington2 object!");
            }
            return Singleton2.instance;
        }
    }

    /* 双重校验锁-线程安全 */
    class Singleton3
    {
        private Singleton3() {} 
        private static object lockObj = new object();
        private static Singleton3 instance = null;

        public static Singleton3 GetInstance()
        {
            if (Singleton3.instance == null)
            {
                lock (Singleton3.lockObj)
                {
                    Singleton3.instance = new Singleton3();
                }
            }
            else
            {
                Console.WriteLine("already have a Sington3 object!");
            }
            return Singleton3.instance;
        }
    };

    class Program
    {
        static void Main()
        {
            Singleton s1 = Singleton.GetInstance();
            Singleton s2 = Singleton.GetInstance();

            Singleton2 s21 = Singleton2.GetInstance();
            Singleton2 s22 = Singleton2.GetInstance();

            Singleton3 s31 = Singleton3.GetInstance();
            Singleton3 s32 = Singleton3.GetInstance();
            
        }
    }
}