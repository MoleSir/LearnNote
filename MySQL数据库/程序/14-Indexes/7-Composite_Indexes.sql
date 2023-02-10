-- 复合索引
USE sql_store;
SHOW INDEXES IN customers;
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA' AND points > 1000;
-- 对两个有索引的列查询
-- possible_keys 有两个，但最后 key = idx_state 最后选中了 idx_state
-- 索引 MySQL 会根据 idx_state 索引先快速找到 'CA' 州的顾客，然后依次遍历浙西顾客判断 points

-- 使用复合索引
CREATE INDEX idx_state_points ON customers (state, points);
-- 创建后再次执行查询，rows 少了很多 
-- possible_keys 多了一共 idx_state_points，最后 MySQL 使用了 idx_state_points