-- 多表连接，超过 2--
-- sql_store 的 orders 表有一列是 status，其只是数字
-- 这些数字对应的含义保存在 order_status 表格中
-- 我们希望连接 orders cutomers order_status 三张表格

USE sql_store;

SELECT 
	o.order_id,
    o.order_date,
    c.first_name,
    c.last_name,
    os.name AS status
FROM orders o
-- 先与 customers 连接 
JOIN customers c ON o.customer_id = c.customer_id
-- 再写一个 JOIN 语句与 order_status 连接
JOIN order_statuses os ON o.status = os.order_status_id 
