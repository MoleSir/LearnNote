USE sql_store;
START TRANSACTION;

UPDATE customers
SET points = 20
WHERE customer_id = 1;

COMMIT;