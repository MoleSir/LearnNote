-- ALL --
USE sql_invoicing;

SELECT *
FROM invoices
WHERE invoice_total > (
	-- 子查询得到一个值
	SELECT MAX(invoice_total)
	FROM invoices
	WHERE client_id = 3);
    
    
-- USE ALL
SELECT *
FROM invoices
-- ALL (150, 230, 167, ...)
-- ALL表示里面的所有数字都要满足 
-- 那么 > ALL(..)，就是要求大于里面的所有，就是大于最大值
WHERE invoice_total > ALL (
	-- 子查询得到了所有 client_id = 3 的 invoices 的 invoice_total
    -- 子查询得到一系列值 
	SELECT invoice_total
    FROM invoices
    WHERE client_id = 3
)