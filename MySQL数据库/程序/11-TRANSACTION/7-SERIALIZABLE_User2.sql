USE sql_store;
START TRANSACTION;

UPDATE customers
-- 正在更新，多加了一个 'VA' 的客户，但是客户 1 会阻塞等待客户 2 提交这个更新
SET state = 'VA'
WHERE customer_id = 1;

COMMIT;