-- 练习多表外连接 --
-- 

USE sql_store;

SELECT 
	o.order_date,
    o.order_id,
    c.first_name,
    s.name AS shipper,
    os.name AS status
FROM orders o
-- 与 cutomers 左连接，获取获取的客户姓，强制显示所有的 orders
JOIN customers c
	ON o.customer_id = c.customer_id
-- 与 shipper 获取订货人
LEFT JOIN shippers s
	ON s.shipper_id = o.shipper_id
-- 与 order_statuses 连接，获取状态
JOIN order_statuses os
	ON os.order_status_id = o.status
