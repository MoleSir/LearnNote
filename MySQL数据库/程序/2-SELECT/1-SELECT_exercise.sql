--################ 练习 ################
-- 从 products 表中查询 name, unit_price, unit_price * 1.1 三个属性，并且把 unit_price * 1.1 命名为 new price
-- 选择数据库
USE sql_store;

-- 查询
SELECT name, unit_price, unit_price * 1.1 AS 'new price' 
FROM products;