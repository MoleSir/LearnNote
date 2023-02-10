/* C++ 实现组合模式 */
#include <iostream>
#include <string>
#include <list>


namespace CompsitePattern
{
    /* 员工类 */
    class Employee
    {
        // 声明友元方便打印
        friend std::ostream& operator << (std::ostream& os, Employee* employee);
    public:
        // 构造函数
        Employee(const std::string& name, const std::string& dept, int salary):
            _name(name), _dept(dept), _salary(salary), _subordinates()
        {}
        // 添加员工到其管理之下
        void AddEmployee(Employee* employee)
        {
            this->_subordinates.push_back(employee);
        }
        // 获得员工链表
        const std::list<Employee* >& GetSubordinates() const
        {
            return this->_subordinates;
        }
    private:
        // 员工的属性：名称、职务、薪水
        std::string _name;
        std::string _dept;
        int _salary;
        // 管理的员工
        std::list<Employee* > _subordinates;
    };

    std::ostream& operator << (std::ostream& os, Employee* employee)
    {
        os << "[Name: " << employee->_name << ", Dept: " << employee->_dept 
           << ", Salary: " <<  employee->_salary << "]\n"; 
        return os;
    }
}


int main()
{
    using namespace CompsitePattern;
    // 创建一些打工人
    Employee* CEO = new Employee("John", "CEO", 50000);

    Employee* headSales = new Employee("Robert","Head Sales", 30000);
    Employee* headMarketing = new Employee("Michel","Head Marketing", 30000);

    Employee* clerk1 = new Employee("Laura","Marketing", 15000);
    Employee* clerk2 = new Employee("Bob","Marketing", 15000);
    Employee* salesExecutive1 = new Employee("Richard","Sales", 12000);
    Employee* salesExecutive2 = new Employee("Rob","Sales", 12000);
    
    // 创建管理关系
    CEO->AddEmployee(headSales);
    CEO->AddEmployee(headMarketing);

    headSales->AddEmployee(salesExecutive1);
    headSales->AddEmployee(salesExecutive2);

    headMarketing->AddEmployee(clerk1);
    headMarketing->AddEmployee(clerk2);

    // 打印一下:
    std::cout << CEO;
    for (Employee* headEmployee : CEO->GetSubordinates())
    {
        std::cout << "    " << headEmployee;
        for (Employee* employee : headEmployee->GetSubordinates())
        {
            std::cout << "        "<< employee;
        }
    }

    // 释放员工
    delete CEO;
    delete headSales;
    delete headMarketing;
    delete clerk1;
    delete clerk2;
    delete salesExecutive1;
    delete salesExecutive2;

    return 0;
}