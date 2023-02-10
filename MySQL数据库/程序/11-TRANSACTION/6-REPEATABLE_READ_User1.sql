USE sql_store;
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- 解决
START TRANSACTION;
SELECT points FROM customers WHERE customer_id = 1;
SELECT points FROM customers WHERE customer_id = 1;
COMMIT;

-- 仍存在的问题
START TRANSACTION;
-- 尝试读取
SELECT * FROM customers WHERE state = 'VA';
COMMIT;