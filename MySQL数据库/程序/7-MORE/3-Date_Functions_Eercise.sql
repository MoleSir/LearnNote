-- 联系日期函数
-- 选出今年的订单
USE sql_store;
SELECT *
FROM orders
WHERE YEAR(order_date) = YEAR(NOW());