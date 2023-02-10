USE sql_store;
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
-- 使用了 READ COMMITTED 隔离等级，不会查询到没有被提交的数据 --> 解决脏读 
SELECT points
FROM customers
WHERE customer_id = 1;

-- 仍存在的问题
START TRANSACTION;
SELECT points FROM customers WHERE customer_id = 1;
SELECT points FROM customers WHERE customer_id = 1;
COMMIT;