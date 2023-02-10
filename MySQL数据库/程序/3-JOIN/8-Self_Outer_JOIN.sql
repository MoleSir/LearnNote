-- 自外连接 --
USE sql_hr;


-- 在自连接的例子中，因为有人没有报告人，所以用内连接这个人是不会出现的
-- 使用外连接可用解决这个问题
SELECT 
	e.employee_id,
    e.first_name,
    m.first_name AS manager
FROM employees e
LEFT JOIN employees m
	ON e.reports_to = m.employee_id