-- 将不同数据库中的表格连接 ---
-- 使用 数据库名称作为前缀即可
-- 将 sql_store 中的 order_items 与 sql_inverntory 中的 products连接
SELECT * 
FROM sql_store.order_items oi
JOIN sql_inventory.products p
ON oi.product_id = p.product_id