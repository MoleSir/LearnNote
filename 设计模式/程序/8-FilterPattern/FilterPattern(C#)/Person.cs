using System;

namespace FilterPattern
{
    public class Person
    {
        // 构造函数
        public Person(string name, string gender, string maritalStatus)
        {
            this.name = name;
            this.gender = gender;
            this.maritalStatus = maritalStatus;
        }
        // getter
        public string GetName()
        {
            return this.name;
        }
        public string GetGender()
        {
            return this.gender;
        }
        public string GetMaritalStatus()
        {
            return this.maritalStatus;
        }
        
        private string name;
        private string gender;
        private string maritalStatus;
    }
}