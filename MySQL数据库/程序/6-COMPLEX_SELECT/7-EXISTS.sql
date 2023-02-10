-- EXISTS --
-- Select clients that have an invoice
USE sql_invoicing;

-- IN
SELECT *
FROM clients
WHERE client_id = ANY (
	SELECT DISTINCT client_id
    FROM invoices
);

-- EXISTS
SELECT *
FROM clients c
-- 使用 EXISTS ，检测这个表中是否存在满足以下的行：
WHERE EXISTS (
	SELECT client_id
    FROM invoices
    -- 检测当前 clients 表中的某行的 client_id 是否存在于 invoices 的 client_id 相同的
    -- 如果存在，这个行就会被筛选出来； 
    WHERE client_id = c.client_id
)