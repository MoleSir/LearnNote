-- 练习 --
USE sql_store;

-- USE Subsqueres
SELECT customer_id, first_name, last_name
FROM customers
WHERE customer_id IN (
	SELECT o.customer_id
    FROM order_items oi
    JOIN orders o 
		ON o.order_id = oi.order_id
    WHERE product_id = 3
);


-- USE JOIN
SELECT DISTINCT customer_id, first_name, last_name
FROM customers c
JOIN orders o USING (customer_id)
JOIN order_items oi USING (order_id)
WHERE oi.product_id = 3
