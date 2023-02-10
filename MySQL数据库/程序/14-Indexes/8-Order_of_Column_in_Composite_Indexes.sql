-- 复合索引中的排序问题
-- 1. 更频繁使用的列排在前面
-- 2. 基数更高的列排在最前面（基数表示索引中唯一值的数量）
-- 3. 顾及具体查询
-- MySQL 会选择最佳的索引，但可以强制
USE sql_store;
EXPLAIN SELECT customer_id
FROM customers
USE INDEX (idx_lastname_state)
WHERE state = 'NY' AND last_name LIKE 'A%';