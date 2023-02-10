/*
* 以下是一个简易的 StringBuilder 实现
*/
using System;

namespace BuilderPatternApplication
{
    class Program
    {
        static void Main()
        {
            StringBuilder sb = new StringBuilder(16);

            int count = 26;
            for (int i = 0; i < count; i++) 
            {
                char ch = (char)(i + (int)('a'));
                sb.Append(ch);
            }
            Console.WriteLine(sb.ToString());
        }
    }
}