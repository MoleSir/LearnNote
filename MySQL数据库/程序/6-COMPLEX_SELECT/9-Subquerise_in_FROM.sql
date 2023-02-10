-- FROM 中的子查询 --
-- 当我们得到一张表格，比如在 8 里面的练习 
-- 我们已经使用过了 WHERE 了，那么如果我们还想再来一次筛选怎么办？
-- 这就需要我们在 FROM 后加 子查询
-- 其实 FROM 后就是一个表，那么我们刚刚得到的不就是一张表格吗？
-- 就相当于我们去取这个表进行操作： 
SELECT *
FROM (
	-- 这个子查找得到一张表，我们把这个表作为 FROM 的原始数据，继续操作 
	SELECT 
		client_id,
		name,
		(SELECT SUM(invoice_total) 
		FROM invoices  
		WHERE client_id = c.client_id) AS total_sales,
		(SELECT AVG(invoice_total) FROM invoices) AS average,
		(SELECT total_sales - average) AS differnece
	FROM clients c
-- 但是注意，我们必须给这个计算得到的表一个名字
) AS sales_summary
WHERE total_sales IS NOT NULL