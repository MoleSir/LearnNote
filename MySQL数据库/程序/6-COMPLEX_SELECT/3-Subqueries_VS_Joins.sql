-- Subquerics VS Joins --
-- Find the products that have never been ordered
USE sql_store;

SELECT *
FROM products
WHERE product_id NOT IN (
	SELECT DISTINCT product_id 
	FROM order_items
);

-- use joins
SELECT *
FROM clients
LEFT JOIN invoices USING (client_id)
WHERE invoice_id IS NULL;