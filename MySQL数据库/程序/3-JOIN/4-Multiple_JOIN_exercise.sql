-- ---------------多表连接练习------------------
-- 在  sql_invoicing 中，有 payments 表，
-- 其中有 payment_method 属性，只是数字，其映射保存在 payment_methods 中
-- 其中还有 clients_id，保存客户的 id，客户的信息保存在 clients 中
-- 把三表合并，显示完整信息

USE sql_invoicing;

SELECT 
	p.date,
    p.invoice_id,
    p.amount,
    c.name,
    pm.name
FROM payments p
JOIN payment_methods pm
	ON p.payment_method = pm.payment_method_id
JOIN clients c
	ON p.client_id = c.client_id;