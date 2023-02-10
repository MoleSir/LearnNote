/* C#实现组合模式 */
using System;
using System.Collections.Generic;


namespace CompositePattern
{
    public class Employee 
    {
        // 构造函数
        public Employee(string name, string dept, int salary)
        {
            this.name = name;
            this.dept = dept;
            this.salary = salary;
            this.subordinates = new List<Employee>();
        }
        // 添加员工
        public void AddEmployee(Employee employee)
        {
            this.subordinates.Add(employee);
        }
        // 获取链表
        public List<Employee> GetSubordinates()
        {
            return this.subordinates;
        }
        // 打印信息
        public void PrintMessage()
        {
            Console.WriteLine("[Name: {0}, Dept: {1}, Salary: {2}]",
                                this.name, this.dept, this.salary);
        }

        // 员工的属性
        private string name;
        private string dept;
        private int salary;
        // 管理的员工链表
        private List<Employee> subordinates; 
    }


    public class Program
    {
        static void Main(string[] args)
        {
            Employee CEO = new Employee("John","CEO", 30000);
        
            Employee headSales = new Employee("Robert","Head Sales", 20000);
        
            Employee headMarketing = new Employee("Michel","Head Marketing", 20000);
        
            Employee clerk1 = new Employee("Laura","Marketing", 10000);
            Employee clerk2 = new Employee("Bob","Marketing", 10000);
        
            Employee salesExecutive1 = new Employee("Richard","Sales", 10000);
            Employee salesExecutive2 = new Employee("Rob","Sales", 10000);
        
            CEO.AddEmployee(headSales);
            CEO.AddEmployee(headMarketing);
        
            headSales.AddEmployee(salesExecutive1);
            headSales.AddEmployee(salesExecutive2);
        
            headMarketing.AddEmployee(clerk1);
            headMarketing.AddEmployee(clerk2);
        
            //打印该组织的所有员工
            CEO.PrintMessage();
            foreach (Employee headEmployee in CEO.GetSubordinates()) 
            {
                Console.Write("    ");
                headEmployee.PrintMessage();
                foreach (Employee employee in headEmployee.GetSubordinates()) 
                {
                    Console.Write("        ");
                    employee.PrintMessage();
                }
            }
        }
    }
}

