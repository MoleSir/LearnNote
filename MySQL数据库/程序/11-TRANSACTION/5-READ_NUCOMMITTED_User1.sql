USE sql_store;
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
-- MySQL 自动将没有被设置在事务中的语句视为一个事务提交
-- 所以下面的 SELECT 就是一个事务，并且隔离等级为 READ UNCOMMITTED
-- 此事务会读取其他事务没有提交的数据
SELECT points
FROM customers
WHERE customer_id = 1;