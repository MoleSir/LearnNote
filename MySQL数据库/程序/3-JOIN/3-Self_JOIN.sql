-- 在同一个表格中 JOIN --
-- 这个例子使用 sql_hr 中的 employee 表格
-- 每个员工有一个 id 属性，还有一个报告人 id 属性
-- 这个属性表示某个员工应该向谁发现报告
-- 我们希望查询出来的数据在每个员工后跟上其报告人信息
-- 就是我们需要匹配表格的 reports_to 与 employee_id 属性 

USE sql_hr;

# 显示员工的 id、员工的 姓、员工的报告人 姓
SELECT e.employee_id, e.first_name, m.first_name AS manager
FROM employees e -- 必须给同一张表名不同的名称来进行后续的条件判断
JOIN employees m
ON e.reports_to = m.employee_id