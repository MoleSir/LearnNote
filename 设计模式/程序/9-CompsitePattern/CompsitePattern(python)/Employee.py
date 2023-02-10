# 员工类
class Employee(object):
    # 构造函数
    def __init__(self, name, dept, salary):
        self.name = name
        self.dept = dept
        self.salary = salary
        self.subordinates = []
    # 添加员工
    def AddEmployee(self, employee):
        self.subordinates.append(employee)
    # 打印信息
    def ShowInfomation(self):
        print("[Name: {}, Dept: {}, Salary: {}]".format(self.name, self.dept, self.salary))
