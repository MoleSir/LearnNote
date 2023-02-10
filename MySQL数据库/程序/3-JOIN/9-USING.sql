-- USING 语句 ---
USE sql_store;

-- 当条件是两表中相同的属性，比如这里都是 customer_id
SELECT
	o.order_id,
    c.first_name
FROM orders o
JOIN customers c
	ON o.customer_id = c.customer_id;
    
-- 使用 UINGSE 简化
SELECT
	o.order_id,
    c.first_name,
    sh.name AS shipper
FROM orders o
JOIN customers c
	USING(customer_id)
LEFT JOIN shippers sh
	USING(shipper_id);
    
-- 多条件 USING 
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	ON oi.order_id = oin.order_id 
    AND oi.product_id = oin.product_id;
    
-- 使用 USING 简化
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	USING(order_id, product_id);