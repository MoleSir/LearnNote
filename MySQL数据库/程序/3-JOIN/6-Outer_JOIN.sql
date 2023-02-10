-- 外连接 --
-- 之前我们使用的 JOIN 都是内连接，SQL 有两种连接方式： 
	-- INNER JOIN 内连接
    -- OUTER JOIN 外连接又分为左连接与右连接
		-- LEFT OUTER JOIN
        -- RIGHT OUTER JOIN

-- 如果我们只写 JOIN 默认就是内连接
-- 内连接与外连接的区别不大，就是如果我们使用内连接
-- 如果某些表项没有我们给定的能够条件中的属性，既为 null，这个表项不会被选中
-- 还是比如 employee 的例子，所有人除了 CEO 都有一个 report_id 属性， CEO 的是 null
-- 那么我们使用 内连时，CEO 就不会被显示到结果中，因为他没有 report_id 属性

-- 那么如果我们希望属性为 null 的也可显示出来就需要使用外连接
-- 使用外JOIN之前，还需要明确一下JOIN的顺序 
-- 写在 FROM 表格是左表，写在 JOIN 后的表格是表
-- 使用 LEFT JOIN 时代表，不管左表的表项是否满足条件都要把其显示
-- RIGHT JOIN 则是对于右表；

-- 例如：将 orders 连接到 customers 中，条件是二者的 customer_id 相同
-- customers 保存 1-10 号 customer_id 的十位顾客，orders 中的 customer_id 代表对于 order 属于哪个 customers
-- 显然，customers 中的 customer_id 不重复，而 orders 的 customer_id 重复了，并且有遗漏，因为 1, 3, 9号顾客没有订单
-- 内JOIN: 结果中没有 1, 3, 4, 9 顾客
USE sql_store;
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM customers c
JOIN orders o
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id;

-- LEFT JOIN: 左JOIN，保证左表格 customers 的每一项都出现
USE sql_store;
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM customers c
LEFT JOIN orders o
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id;

-- RIGHT JOIN: 右JOIN，保证右表格 customers 的每一项都出现
USE sql_store;
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM orders o
RIGHT JOIN customers c
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id
