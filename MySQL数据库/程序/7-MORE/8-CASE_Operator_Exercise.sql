-- CASE 练习
USE sql_store;
SELECT 
	CONCAT(first_name, ' ', last_name) AS full_name,
	points,
    CASE
		WHEN points > 3000 THEN 'Glod'
        WHEN points >= 2000 THEN 'Silver'
        ELSE 'Bronze'
    END AS category
FROM customers