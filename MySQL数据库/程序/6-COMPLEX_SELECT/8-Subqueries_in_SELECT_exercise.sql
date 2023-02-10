-- SELECT 中的子查询 --
USE sql_invoicing;

SELECT 
	client_id,
    name,
    (SELECT SUM(invoice_total) 
     FROM invoices  
	 WHERE client_id = c.client_id) AS total_sales,
	(SELECT AVG(invoice_total) FROM invoices) AS average,
	(SELECT total_sales - average) AS differnece
FROM clients c