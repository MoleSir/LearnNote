-- 修改或者删除视图
-- 使用创建视图 CREATE VIEW 只能执行一次
-- 如果发现写的视图查询是错的，就需要修改
-- 可以先删除
DROP VIEW sales_by_client;
-- 之后再去修改程序，再次生产查询

-- 或直接使用 REPLACE，这样这个命令可以执行无限次
USE sql_invoicing;
CREATE OR REPLACE VIEW clients_balance AS 
SELECT 
	c.client_id,
    c.name,
    SUM(invoice_total - payment_total) AS balance
FROM clients cclients_balanceclients_balance
JOIN invoices i USING (client_id)
GROUP BY client_id, name;

-- 视图并不会包含数据，只是一段代码，可以把源码保存，需要使用就调用，这是最好的方式
-- 点击视图的扳手按钮，可以看到源码，MySQL 在我们写的基础上再添加了一些东西
	-- 特别是其将属性名称、表名称都加上 ``，防止名称与关键字冲突 
    
-- 所以可以直接修改这个文件来修改视图