-- HAVING 语句 --
USE sql_invoicing;

-- 我们希望总价 total_sales 超过 500 的组合才显示
-- 但是不可以使用 WHERE，因为 WHERE 是针对还没有分组之前的数据alter
-- total_sales 还没算出
SELECT 
	client_id,
    SUM(invoice_total) AS total_sales
FROM invoices
GROUP BY client_id
-- HAVING 语句在分组后再对数据进行筛选，这里是对分组后，经过函数计算得到的那些记录筛选
-- 已经不是原始数据了
HAVING total_sales > 500;

-- 多条件 HAVING
SELECT 
	client_id,
    SUM(invoice_total) AS total_sales,
    -- COUNT 计算的是各个分组各自的记录数量
    COUNT(*) AS number_of_invoices
FROM invoices
GROUP BY client_id
-- 跟 WHERE 的多条件一样，但 HAVING 里面的条件用到的属性一定是要被选中的，跟 WHERE 不一样
HAVING total_sales > 500 AND number_of_invoices > 5