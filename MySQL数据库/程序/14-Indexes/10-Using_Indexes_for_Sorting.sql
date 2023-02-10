-- 使用索引排序
USE sql_store;
SHOW INDEXES IN customers;

-- 创建索引会进行排序，那么如果查询结果也时候索引的列排序，就直接读取索引的排序结果即可
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state;
-- type : idx_state_poinrs，使用索引排序
-- Extra : Using index 
-- 花费 102

-- 对没有索引的列排序
EXPLAIN SELECT customer_id
FROM customers
ORDER BY first_name;
-- Extra : Using filesort 很耗时
-- type ALL
-- 花费 1112

-- 查看 MySQL 服务器变量：上次查询花费
SHOW STATUS LIKE 'last_query_cost';


-- 有复合索引，对复合的列排序也有作用
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state, points;
-- type : idx_state_poinrs，使用索引排序
-- Extra : Using index 
-- 花费 102

-- 两个排序方向不同：
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state, points DESC;
-- Extra : Using index; Using filesort

-- 两个都相反的话也是很快

-- 增加一个没有索引的列也慢

-- 对复合索引的后一列排序
DROP INDEX idx_points ON customers;
EXPLAIN SELECT customer_id
FROM customers
ORDER BY points;
-- Extra : Using index, Using filesort
-- 慢，因为 idx_state_points 是先对 state 排序，对同样的 state 再对 pointes 排序
-- 而这个查询是直接对所有 points 排序，还是需要全部重新排序

-- 加一个 WHERE 就可以解决，这样就对同样的 state 进行 points 排序，这个排序在索引中已完成
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA'
ORDER BY points;

-- 对 a, b 列的索引：(a, b)
	-- a
    -- b
    -- a, b
    -- a DESC, b DESC
    -- b
    -- ...