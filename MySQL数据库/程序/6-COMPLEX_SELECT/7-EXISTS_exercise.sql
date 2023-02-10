-- EXISTS 练习 --
-- Find the products that have never been ordered
USE sql_store;


SELECT *
FROM products p
WHERE p.product_id <> ALL( 
	SELECT DISTINCT product_id
    FROM order_items
);

SELECT * 
FROM products p
WHERE NOT EXiStS(
	SELECT *
    FROM order_items
    WHERE p.product_id = product_id
)