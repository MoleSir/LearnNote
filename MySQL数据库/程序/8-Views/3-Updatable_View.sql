-- 可更新视图 
-- 在创建视图的代码中，在 SELECT FROM 后使用了视图，仅仅选择其中的数据，没有对其修改
-- 视图在某些情况下可以进行 INSERT、UPDATE、DELETE 语句；可以进行这个修改操作的视图称为可更新视图 update view
-- 可更新视图必须不包含：DISTNCT、Aggregate 聚合函数、GROUP BY / HAVING 与 UNION；
-- 不包含上述所有操作的视图称为可更新视图

-- 这个视图就是一个可更新视图
USE sql_invoicing;
CREATE OR REPLACE VIEW invoices_with_balance AS
SELECT   
	invoice_id,
    number,
    client_id,
    invoice_total,
    payment_total,
    invoice_total - payment_total AS balance,
    invoice_date,
    due_date,
    payment_date
FROM invoices
WHERE (invoice_total - payment_total) > 0
WITH CHECK OPTION;

-- 可以对其更改
DELETE FROM invoices_with_balance
WHERE invoice_id = 1;

-- 会改变原来的表格数据
UPDATE invoices_with_balance
SET due_date = DATE_ADD(due_date, INTERVAL 2 DAY)
WHERE invoice_id = 2;









