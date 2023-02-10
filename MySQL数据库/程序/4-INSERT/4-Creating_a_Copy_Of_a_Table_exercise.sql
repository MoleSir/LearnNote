-- 复制练习 --
USE sql_invoicing;

CREATE TABLE invoices_archived AS 
-- SELECT 得到的一张表格
SELECT 
	i.invoice_id,
	i.number,
    c.name AS client,
    i.invoice_total,
    i.payment_total,
    i.invoice_date,
    i.payment_date,
    i.due_date
FROM invoices i
JOIN clients c
	USING (client_id)
-- 上面的连接语句得到一张表，我们可以继续对其筛选
WHERE payment_date IS NOT NULL