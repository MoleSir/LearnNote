-- IN 练习 --
-- Find clinet without invoices
USE sql_invoicing;

SELECT *
FROM clients 
WHERE client_id NOT IN (
	SELECT DISTINCT client_id
	FROM invoices
)

