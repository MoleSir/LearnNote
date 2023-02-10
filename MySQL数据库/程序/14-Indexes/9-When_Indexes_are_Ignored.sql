-- 索引被忽略
-- 这个查询使用了 idx_state_pointes 索引，但还是需要查询 1010 条数据
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA' OR points > 1000;

CREATE INDEX idx_points ON customers (points);
-- 解决方式：把查询拆分
EXPLAIN 
	SELECT customer_id
    FROM customers
    WHERE state = 'CA'
    UNION
    SELECT customer_id
    FROM customers
    WHERE points > 1000;
    
-- 索引无效
EXPLAIN SELECT customer_id
FROM customers
-- 由于这个表达式，MySQL 无法以最优方式利用索引
WHERE points + 10 > 2010;

EXPLAIN SELECT customer_id
FROM customers
-- 想让 MySQL 优化查询，必须把列单独提出
WHERE points > 2000;