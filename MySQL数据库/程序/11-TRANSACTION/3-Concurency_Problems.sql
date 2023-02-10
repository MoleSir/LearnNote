-- 并发时不上锁的问题：
	-- Lost Updates，当两个事务更新同一行，最后提交的事务覆盖了先前所做的修改；
    -- Dirty Reads，指一个事务读取了尚未被提交的数据；
		-- 比如事务 A 先修改了 points 属性，但在其提交之前，事务 B 读取了 points，之后事务 A 有语句失败
		-- 那么 A 对 pointes 的修改被撤回，B 却拿到了修改后的错误的 points
	-- Non-repeating Reads，在事务中读取相同的数据两次得到不同的结果；
		-- 比如：事务 A 先读取 ponits，事务 B 再修改 points，事务 A 最后读取 points，导致事务 A 前后读取的 points 不一样；
    -- Phantom Reads，当查询中缺少了一行或者多行，因为另一个事务正在修改数据；
		-- 比如务 A 对查询表格的过程中，事务 B 插入新的数据，导致事务 A 查询结果不正确
	