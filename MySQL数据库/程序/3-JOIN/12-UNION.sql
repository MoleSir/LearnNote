-- 联合 --
-- 联合 UNION 可以把两次 SELECT 的结果合并
-- 下面的例子把从 orders 中查到的 19 年之后的订单与 19年之前的订单联合
-- 并且给两个 SELECT 打上不同的标签 
-- 联合两个 SELECT 得到的属性个数要一致，才能联合起来 
-- 最后联合得到的属性名称与第一个 SELECT 的一致 
SELECT 
	order_id,
    order_date,
    'Active' AS status
FROM orders
WHERE order_date >= '2019-01-01'

UNION

SELECT 
	order_id,
    order_date,
    'Archived' AS status
FROM orders
WHERE order_date < '2019-01-01';


SELECT 
	first_name,
    "c" AS tag
FROM customers
UNION
SELECT 
	name,
    "s" AS tag
FROM shippers;