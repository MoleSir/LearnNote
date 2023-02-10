############## 练习 IS NULL ##############
## 获取没有 shipped 的订单
USE sql_store;

SELECT *
FROM orders
WHERE shipper_id IS NULL;