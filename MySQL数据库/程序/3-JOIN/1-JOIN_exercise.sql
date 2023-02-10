-- ---------------- 练习 --------------------
-- 以 product_id 相同为依据显示 order_items 与 products 表格
-- 中的 order_id, product_id, quantiy, uint_price
USE sql_store;

SELECT order_id, oi.product_id, quantity, oi.unit_price
FROM order_items oi
JOIN products p
ON oi.product_id = p.product_id;
