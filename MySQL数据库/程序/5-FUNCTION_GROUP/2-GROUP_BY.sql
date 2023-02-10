-- 数据分组 --
USE sql_invoicing;

-- invoices 中有属性 invoice_total 与 clinet_id
-- 其中 clinet_id 是重复的，也就是所每个客户有多条 invoices
-- 我们希望显示每个用户自己的 invoice_total 总和：
SELECT
	client_id,
	SUM(invoice_total) AS total_sales
FROM invoices
-- 先筛选掉一些，WHRER 需要在 GROUP BY 之前，排序 ORDER BY 在之后，最后 LIMIT，这是很自然的
-- 先筛选、再分组、最后排序；
WHERE invoice_date >= '2019-07-01'
-- 以 clinet_id 为根据，将 client_id 相同的行视为一组
GROUP BY client_id
ORDER BY total_sales DESC;


-- - 联合
SELECT
	state,
    city,
    SUM(invoice_total) AS total_sales
FROM invoices i
JOIN clients c
	ON i.client_id = c.client_id
-- 多个属性来分组，要求这两个属性都相同的才算一组 
GROUP BY state, city 