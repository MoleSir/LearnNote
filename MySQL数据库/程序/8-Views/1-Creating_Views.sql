-- 创建视图 View
USE sql_invoicing;

-- 这个查询结果之后可能多次用到，希望可以将其保存
-- 就可以使用 VIEW 视图，在 查询前写 [CREATE VIEW 视图名称 AS] 即可
-- 创建视图对象后，查询结果不会显示，而是出现在导航面板中
-- 在数据库的视图面板下sales_by_client
-- 可以就把这个视图当作一个新的数据表
CREATE VIEW sales_by_client AS
SELECT 
	c.client_id,
    c.name,
    SUM(invoice_total) AS total_sales
FROM clients c
JOIN invoices USING (client_id)
GROUP BY client_id, name;

-- 像表格一样使用视图
SELECT *
FROM sales_by_client
ORDER BY total_sales 