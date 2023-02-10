-- 更新多条语句 --
-- 就是把更新一条语句后的 WHERE 条件改了，让多行满足即可
-- 但在 MySQL 工作台中默认开启安全模式，不允许修改多行；
-- 需要做一些设置：
	-- Edit 
		-- Rreferences
			-- SQL Editer
				-- 拉到最后，将 Safe Update 取消勾选
USE sql_invoicing;

UPDATE invoices
SET 
	-- 可以使用其他属性来赋值，写在 = 右边的属性是原来的值，i = i + 1，很好理解吧！
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
WHERE client_id = 3; -- WHRER 是可选的，如果要更新表中所有数据，不写 WHERE即可