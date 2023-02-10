-- 事务隔离级别 
-- MySQL 提供四种标准事务隔离
	-- READ UNCOMMITED：运行事务读取没有被提交的数据，不设置任何锁，就是导致这些问题的原因；
	-- READ COMMITED：事务只能读取已经提交的数据，防止了 Dirty Read 
    -- REPEATBALE READ：在这个级别，MySQL 确保读取到的数据返回相同的结果
    -- SERIZLIZABLE（可序化）：可以解决所有问题，若干数据在期间改动，事务会待定，以获取最新数据，增加负担，但可靠；

-- MySQL 默认的事务隔离级别是 REPEATBALE READ；可以解决 Phantom Read 以外的三个并发问题

-- 查看当前的事务隔离
SHOW VARIABLES LIKE 'transaction_isolation';

-- 修改事务隔离等级
-- 设置下一次事务的隔离等级为 ...
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
-- 设置本次 MySQL 连接所创建的事务隔离等级为 ...
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
-- 设置之后的所有事务等级为...
SET GLOBAL TRANSACTION ISOLATION LEVEL SERIALIZABLE;