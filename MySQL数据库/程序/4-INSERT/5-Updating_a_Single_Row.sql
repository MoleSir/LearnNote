-- 更新一行数据，使用 UPDATE 
USE sql_invoicing;

-- 首先选择要更新的表格
UPDATE invoices
-- 属性如何改变，这里让 payment_total 变为 10，payment_date 变为 2019-03-01
SET payment_total = 10, payment_date = '2019-03-01'
-- WHERE 筛选，选出哪些行需要修改，这里选择 invoice_id = 1 的修改
WHERE invoice_id = 1;


UPDATE invoices
SET 
	-- 可以使用其他属性来赋值，写在 = 右边的属性是原来的值，i = i + 1，很好理解吧！
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
WHERE invoice_id = 3;