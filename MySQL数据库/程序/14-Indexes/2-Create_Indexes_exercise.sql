-- 创建索引练习
USE sql_store;
EXPLAIN SELECT customer_id 
FROM customers
WHERE points > 1000;

CREATE INDEX idx_points ON customers (points);