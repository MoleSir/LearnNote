-- 若干多个用户访问一个数据库出现并发问题
-- 当一个用户对一个表进行事务操作，MySQL 给此表上锁
-- 其他的用户使用事务操作这个表会阻塞，直到第一个用户的事务被 COMMIT 完成
USE sql_store;
START TRANSACTION;
UPDATE customers
SET points = points + 10
WHERE customer_id = 1;
COMMIT;
