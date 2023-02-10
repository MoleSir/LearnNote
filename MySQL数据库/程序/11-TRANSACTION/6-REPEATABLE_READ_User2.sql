USE sql_store;
START TRANSACTION;

UPDATE customers
-- 正在更新，多加了一个 'VA' 的客户，但是客户1 看不到
SET state = 'VA'
WHERE customer_id = 1;

COMMIT;