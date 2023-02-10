############## 练习 ##################
-- 从 order_items 表中得到 order 为 #6 并且 total price 大于 30 的所有商品

# 选择数据库
USE sql_store;

SELECT * 
FROM order_items
WHERE order_id = 6 AND unit_price * quantity > 30;