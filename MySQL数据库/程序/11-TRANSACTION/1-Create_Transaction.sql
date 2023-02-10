-- 事务是代表单个工作单元的一组 SQL 语句 
-- 所有这些语句都必须同时成功执行，否则就都失败
-- 比如银行，从我的账户取出10元是一个操作，将10元放入我朋友的账户是另一个操作
-- 希望完成我向朋友转账这个工作，必须上述两个操作都完成
-- 如果某个失败，另一个即使成功，也需要撤回

-- 事务特点
	-- 原子性：一个事务的语句要么全部执行成功，要么就相等于没有执行；
    -- 一致性，使用事务，保存数据库的一致性；
    -- 隔离性，事务相互隔离，不会互相干扰，对表正在被某个事务操作时，其他事务必须等待
	-- 持久性：事务一旦被提交，事务产生的影响是永久的
    
-- 创建事务
-- START TRANSACTION;
-- 若干语句，用 ; 结尾
-- COMMIT;
USE sql_store;

START TRANSACTION;

INSERT INTO orders (customer_id, order_date, status)
VALUES (1, '2019-01-01', 1);

INSERT INTO order_items
VALUES (LAST_INSERT_ID(), 1, 1, 1);

COMMIT;