-- IF 函数
-- expression 为真返回 first，否则 second
-- IF(expression, first, second)

USE sql_store;
SELECT 
	order_id,
    order_date,
    -- 不起名字的话就是 IF(，最好自己来一个
	IF(YEAR(order_date) = YEAR(NOW()), 'Active', 'Archived') AS state
FROM orders;

-- 使用 UNOIN ，比较麻烦
SELECT 
	order_id,
    order_date,
    'Active'
FROM orders
WHERE YEAR(order_date) = YEAR(NOW())

UNION 

SELECT 
	order_id,
    order_date,
    'Archived'
FROM orders
WHERE YEAR(order_date) <> YEAR(NOW())

