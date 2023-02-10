-- 死锁
-- 两个客户之间互相等待对方提交


-- User1
USE sql_store;
START TRANSACTION;
UPDATE customers SET state = 'VA' WHERE customer_id = 1;
UPDATE orders SET status = 1 WHERE order_id = 1;
COMMIT;

-- User2，与用户1的更新顺序相反，用户 1 等待用户 2，用户 2 等待用户 1
USE sql_store;
START TRANSACTION;
UPDATE orders SET status = 1 WHERE order_id = 1;
UPDATE customers SET state = 'VA' WHERE customer_id = 1;
COMMIT;