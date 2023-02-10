-- 子查询 Subqueries --

-- Find products that are more
-- expensive than Lecttue (id = 3)
USE sql_store;

SELECT * 
FROM products
WHERE unit_price > (
	SELECT unit_price
    FROM products
    WHERE product_id = 3
)
