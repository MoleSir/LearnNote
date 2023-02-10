-- CASE 运算符
-- if 只能根据真或假，把数据分为两种，如果要多种分类用 CASE
USE sql_store;
SELECT 
	order_id,
	-- WHEN 后条件满足的返回 THEN 后的值
    -- 一条一条顺序判断，满足了就直接返回
    -- 不写 ELSE，都不满足返回 null
    CASE 
		WHEN YEAR(order_date) = YEAR(NOW()) THEN 'Active'
        WHEN YEAR(order_date) = YEAR(NOW()) - 1 THEN 'Last Year'
        WHEN YEAR(order_date) < YEAR(NOW()) - 1 THEN 'Archived'
        -- 都不满足
        ELSE 'Future'
	END AS category
FROM orders