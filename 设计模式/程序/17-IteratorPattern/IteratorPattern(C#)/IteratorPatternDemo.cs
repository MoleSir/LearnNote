/* C#实现迭代器模式 */
using System;

namespace IteratorPattern
{
    public class IteratorPatternDemo 
    {
        public static void Main(string[] args) 
        {
            string[] names = {"Robert" , "John" ,"Julie" , "Lora"};
            NameRepository namesRepository = new NameRepository(names);
 
            for(Iterator iter = namesRepository.GetIterator(); iter.HasNext();)
            {
                string name = (string)iter.Next();
                Console.WriteLine("Name : " + name);
            }  
        }
    }
}