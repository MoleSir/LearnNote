################ 练习 ################
-- 在 orders 表中查询得到 2019 年之后的订单

# 选择数据库
USE sql_store;

SELECT *
FROM orders
WHERE order_date >= '2019-01-01'