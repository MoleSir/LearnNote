-- 聚合函数 --
USE sql_invoicing;

SELECT 
	-- 使用 MAX() 函数，从 invoices 表中选出 invoice_total 属性最大的
	MAX(invoice_total) AS highest,
    -- 使用 MIN() 函数，选出 invoices_tatal 最小的，命名为 lowest
    MIN(invoice_total) AS lowest,
    -- 使用 AVG() 函数，计算出平均值
    AVG(invoice_total) AS average,
    -- 使用 SUM() 函数，计算总和 
    SUM(invoice_total) AS total,
    -- 使用 COUNT() 函数，计算数量，NULL 不会被算进
    COUNT(invoice_total) AS number_of_invoices,
    -- 计算整个表有多少记录：
    COUNT(*) AS total_records,
    -- 参数还可以写表达式
    SUM(invoice_total * 1.1),
    -- 如果几个记录某个属性相同，COUNT 不会去重复
    COUNT(client_id),
    -- 想让 COUNT 去重，使用 DISTING 关键字
    COUNT(DISTINCT client_id)
FROM invoices
-- 表格先经过过滤，得到部分的记录再去执行函数
WHERE invoice_date > '2019-07-01';

-- 不仅可以对数字属性使用
-- SELECT 
	-- MAX(payment_date) AS highest,
    -- MIN(invoice_total) AS lowest,
    -- AVG(invoice_total) AS average
-- FROM invoices;