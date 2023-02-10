-- ANY --
-- Select clients with at least two invoices

USE sql_invoicing;

SELECT *
FROM clients
WHERE client_id IN (
	SELECT client_id
	FROM invoices
	GROUP BY client_id
	HAVING COUNT(*) >= 2);
    
-- 使用 ANY
SELECT *
FROM clients
--  ANY 表示只要满足其中的一个即可
-- 所以 = ANY(...) 只要有一个等于即可
WHERE client_id = ANY (
	-- 子查询得到一系列值
	SELECT client_id
	FROM invoices
	GROUP BY client_id
	HAVING COUNT(*) >= 2);