-- SELECT 中的子查询 --
USE sql_invoicing;

-- 我们想在这个表的每一行后都加上平均值
-- 如果这样写，最后只能得到一列
SELECT 
	invoice_id,
    invoice_total,
    AVG(invoice_total) AS invoice_average
FROM invoices;

-- 需要在 SELECT 后加子查询
SELECT 
	invoice_id,
    invoice_total,
    (SELECT AVG(invoice_total) FROM invoices) AS invoice_average,
    invoice_total - (SELECT invoice_average) AS difference -- 不能直接用 invoice_average ，因为这是刚刚起的名字 
FROM invoices;