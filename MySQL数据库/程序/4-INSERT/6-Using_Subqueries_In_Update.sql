-- 在 UPDATE 中使用 子查询 
-- 比如：我们在 invoices 表中只有客户的 id，没有姓名，它们直接的映射保存在 clients 中
-- 而 id 一般都是数据库内部使用，用户一般操作都是输入名称
-- 那么我们如何根据用户输入的名称来对 invoices 作更新操作
USE sql_invoicing;

UPDATE invoices
SET 
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
-- 我们在括号中写一个 SELECT 语句，在 clients 表查找某个姓名对应的 id
-- 这可以理解为一个函数，一个 SELECT 语句理解为一个可以返回一张表格的函数
-- 这里我们用一个名称只能查到一个id，所以返回了一个 id ，在 括号外的语句看来
-- 这就是一个数字而已！
WHERE client_id = (
	SELECT client_id -- 只选择了 id 返回
    FROM clients
    WHERE name = 'Myworks');
    
    
-- 如果想改多行呢，很简单，让子查询得到多个id 即可：
UPDATE invoices
SET 
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
-- 因为 子查询返回多个值，所以这里不能用等于，必须用 IN 
WHERE client_id IN (
	SELECT client_id -- 只选择了 id 返回
    FROM clients
	-- 筛选出 clients 表格中属性 state 为 'CA' 或者 'NY' 的行的 client_id 属性
    -- 既返回了州位于 'CA' 或 'NY' 的客户的 id
    WHERE state IN ('CA', 'NY'));