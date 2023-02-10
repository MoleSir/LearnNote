-- 覆盖索引：一个包含所有满足查询需要的数据的索引，MySQL 可以不看原数据就得到结果，比如下面这个：
USE sql_store;
-- 只选中 customer_id 主键
EXPLAIN SELECT customer_id 
FROM customers
ORDER BY state;

-- 选所有
EXPLAIN SELECT * 
FROM customers
ORDER BY state;
-- type : ALL
-- Extra : Using filesort
-- 这是因为 idx_state_points 复合索引上就三列：主键、state、points（主键是默认加入的）
-- 所有如果我们只显示 customers_id，MySQL 只看索引表就可以给出结果
-- 显然如果选中所有列，MySQL 必须看原来表 