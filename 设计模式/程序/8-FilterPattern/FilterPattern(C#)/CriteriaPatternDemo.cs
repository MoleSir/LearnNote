using System;
using System.Collections.Generic;

namespace FilterPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Person> persons = new List<Person>();
 
            persons.Add(new Person("Robert","Male", "Single"));
            persons.Add(new Person("John","Male", "Married"));
            persons.Add(new Person("Laura","Female", "Married"));
            persons.Add(new Person("Diana","Female", "Single"));
            persons.Add(new Person("Mike","Male", "Single"));
            persons.Add(new Person("Bobby","Male", "Single"));

            Criteria male = new CriteriaMale();
            Criteria female = new CriteriaFemale();
            Criteria single = new CriteriaSingle();
            Criteria singleMale = new AndCriteria(single, male);
            Criteria singleOrFemale = new OrCriteria(single, female);

            Console.WriteLine("Males: ");
            PrintPersons(male.MeetCriteria(persons));

            Console.WriteLine("\nFemales: ");
            PrintPersons(female.MeetCriteria(persons));

            Console.WriteLine("\nSingle Males: ");
            PrintPersons(singleMale.MeetCriteria(persons));

            Console.WriteLine("\nSingle Or Females: ");
            PrintPersons(singleOrFemale.MeetCriteria(persons));
        }

        static void PrintPersons(List<Person> persons)
        {
            foreach (Person person in persons)
            {
                Console.WriteLine("[Name: {0}, Gender: {1}, MaritalStatus: {2}]", 
                                  person.GetName(), person.GetGender(), person.GetMaritalStatus());
            }
        } 
    }
}