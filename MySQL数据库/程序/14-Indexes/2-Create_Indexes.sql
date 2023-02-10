-- 创建索引
USE sql_store;
-- 解释查询
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA';
-- type = ALL，说明此次查询会遍历所有行
-- rows = 1010，说明要查 1010 行

SELECT COUNT(*)
FROM customers;

-- 创建索引 
-- CREATE INDEX 索引名称 ON 表格名称 (列)
CREATE INDEX idx_state ON customers (state);
-- 此时再执行解释查询
-- type = ref
-- rows = 112