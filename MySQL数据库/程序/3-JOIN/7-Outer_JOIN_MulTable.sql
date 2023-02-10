-- 多表的外连接 --
-- 多表连接其实就是连接多次
USE sql_store;

SELECT 
	c.customer_id,
    c.first_name,
    o.order_id,
    sh.name AS shapper
-- FROM 后的是左表
FROM customers c
-- 先进行一次 cutomers 与 orders 的左 JOIN
LEFT JOIN orders o
	ON c.customer_id = o.customer_id
-- 再进行一次 cutomers 与 shippers 的左 JOIN
LEFT JOIN shippers sh
	ON o.shipper_id = sh.shipper_id
ORDER BY c.customer_id

