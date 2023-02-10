######## ORDER BY 练习 ###############
## 查找 order_items 表中所有 order_id 为 2，并且按 product_id 降序的
SELECT *
FROM sql_store.order_items
WHERE order_id = 2
ORDER BY product_id;