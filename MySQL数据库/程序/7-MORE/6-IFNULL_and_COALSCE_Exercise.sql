-- IFNULL
USE sql_store;
SELECT 
	CONCAT(first_name, ' ', last_name) AS customer,
    IFNULL(phone, 'Unknow') AS phone
FROM customers