using System;
using System.Collections.Generic;

namespace FilterPattern
{
    /* 接口 */
    public interface Criteria
    {
        List<Person> MeetCriteria(List<Person> persons);
    }

    /* 判断是否为男性 */
    public class CriteriaMale: Criteria
    {
        public List<Person> MeetCriteria(List<Person> persons)
        {
            List<Person> malePersons = new List<Person>();
            foreach (Person person in persons)
            {
                if (person.GetGender() == "Male")
                    malePersons.Add(person);
            }
            return malePersons;
        }
    }

    /* 判断是否为女性 */
    public class CriteriaFemale: Criteria
    {
        public List<Person> MeetCriteria(List<Person> persons)
        {
            List<Person> femalePersons = new List<Person>();
            foreach (Person person in persons)
            {
                if (person.GetGender() == "Female")
                    femalePersons.Add(person);
            }
            return femalePersons;
        }
    }

    /* 判断是否为女性 */
    public class CriteriaSingle: Criteria
    {
        public List<Person> MeetCriteria(List<Person> persons)
        {
            List<Person> singlePersons = new List<Person>();
            foreach (Person person in persons)
            {
                if (person.GetMaritalStatus() == "Single")
                    singlePersons.Add(person);
            }
            return singlePersons;
        }
    }

    /* 合并过滤 */
    public class AndCriteria: Criteria
    {
        // 构造函数
        public AndCriteria(Criteria criteria1, Criteria criteria2)
        {
            this.criteria1 = criteria1;
            this.criteria2 = criteria2;
        }
        // 实现接口
        public List<Person> MeetCriteria(List<Person> persons)
        {
            // 过滤两次
            List<Person> first_persons = this.criteria1.MeetCriteria(persons);
            return this.criteria2.MeetCriteria(first_persons);
        }

        // 两个条件
        private Criteria criteria1;
        private Criteria criteria2;
    }

    /* 或过滤 */
    public class OrCriteria: Criteria
    {
        // 构造函数
        public OrCriteria(Criteria criteria1, Criteria criteria2)
        {
            this.criteria1 = criteria1;
            this.criteria2 = criteria2;
        }
        // 实现接口
        public List<Person> MeetCriteria(List<Person> persons)
        {
            // 过滤两次
            List<Person> first_persons = this.criteria1.MeetCriteria(persons);
            List<Person> second_persons = this.criteria2.MeetCriteria(persons);
            // 把第二次过滤得到的链表放入第一个
            foreach (Person person in second_persons)
            {
                if (!first_persons.Contains(person))
                    first_persons.Add(person);
            }
            return first_persons;
        }

        // 两个条件
        private Criteria criteria1;
        private Criteria criteria2;   
    }

}