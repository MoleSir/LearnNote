-- Correlated Subqueries --
-- above the average in their office

USE sql_hr;

SELECT *
-- 查询 employee 表
FROM employees e
-- 对每个员工依次执行这个 WHERE 
WHERE salary > (
	-- 每个员工都会进入这一次计算，因为其中有与外查询相关 
    -- 若干子查询没有与查询相关，只会执行一次
	SELECT AVG(salary)
    FROM employees
    -- 要求只计算，此时正在被处理的员工那个部门的平均工资
	-- 由于子查询和外查询有相关性，所以称为 相关子查询
    WHERE office_id = e.office_id
)
