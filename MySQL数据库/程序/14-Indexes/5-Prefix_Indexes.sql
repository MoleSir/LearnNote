-- 前缀索引
-- 索引的列如果是字符串等需要多花费很多空间
-- 所以索引字符串时，不需要加入所有字符，只包含前几个字符或列前缀，使得索引比较小
-- 创建索引时候在列后加上 (前缀数量)
CREATE INDEX idx_lastname ON customers (last_name(20));

-- 而需要多少个字符作为前缀，需要根据数据来，不能有太多的重复，需要让每个前缀尽可能唯一标识一个行
-- 测试数据个数，使用 COUNT(DISTINECT 列名称) 计算不重复的项个数，越大当然越好
SELECT COUNT(*) FROM customers;
SELECT 
	COUNT(DISTINCT LEFT(last_name, 1)), -- > 25 太少了，很多重复 
    COUNT(DISTINCT LEFT(last_name, 5)), -- > 966 很不错，一共就 1010 个 
    COUNT(DISTINCT LEFT(last_name, 10)) -- > 还是 966，那么就很没有必要用 10 个前缀，5 个就好
FROM customers;
