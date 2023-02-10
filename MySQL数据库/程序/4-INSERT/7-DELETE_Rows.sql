-- 删除行 --

-- 选择要删除的表
DELETE FROM invoices
-- 筛选哪些行要删除，不写就全部删
WHERE invoice_id = 1;


-- 子查询，跟添加一致
DELETE FROM invoices
-- 筛选哪些行要删除，不写就全部删
WHERE client_id = (
	SELECT *
	FROM clients
	WHERE name = 'Myworks');