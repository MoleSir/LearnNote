from Employee import Employee


CEO = Employee("John","CEO", 30000)

headSales = Employee("Robert","Head Sales", 20000)

headMarketing = Employee("Michel","Head Marketing", 20000)

clerk1 = Employee("Laura","Marketing", 10000)
clerk2 = Employee("Bob","Marketing", 10000)

salesExecutive1 = Employee("Richard","Sales", 10000)
salesExecutive2 = Employee("Rob","Sales", 10000)


CEO.AddEmployee(headSales)
CEO.AddEmployee(headMarketing)

headSales.AddEmployee(salesExecutive1)
headSales.AddEmployee(salesExecutive2)

headMarketing.AddEmployee(clerk1)
headMarketing.AddEmployee(clerk2)


# 打印
CEO.ShowInfomation()
for headEmployee in CEO.subordinates:
    print("    ", end = '')
    headEmployee.ShowInfomation()
    for employee in headEmployee.subordinates:
        print("        ", end = '')
        employee.ShowInfomation()