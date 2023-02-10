-- 交叉连接 --
-- 连接第一个表的所有记录和第二个表的所有记录
-- 比如，a 表有 n 个记录，b 表有 m 个记录
-- 交叉连接会把依次把 a 表出的 n 个记录取出，分别把 b 表中的 m 个记录加入到其中的每一个记录中
-- 最后得到了 m * n 个记录
SELECT 
	c.first_name AS customer,
    p.name AS product
FROM customers c
CROSS JOIN products p
ORDER BY c.first_name;

-- 另一种写法：
SELECT 
	c.first_name AS customer,
    p.name AS product
FROM customers c, orders o
ORDER BY c.first_name