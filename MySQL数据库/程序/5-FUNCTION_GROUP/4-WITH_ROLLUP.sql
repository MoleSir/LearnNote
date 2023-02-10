-- WITH ROLLUP MySQL 特有  --
USE sql_invoicing;

SELECT 
	state,
    city,
    SUM(invoice_total) AS total_sales
FROM invoices i
JOIN clients c USING (client_id)
-- 获取一行汇总，每组的每行的列相加得到
GROUP BY state, city WITH ROLLUP