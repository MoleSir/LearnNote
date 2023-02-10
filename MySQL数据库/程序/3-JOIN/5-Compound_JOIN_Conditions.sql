-- 多条件 JOIN --
-- 很多情况下，我们不能只凭单一的条件就可以 JOIN 成功
-- 比如我要用让 order_items JOIN 到某张表格中
-- 如果我们使用 order_items 的 order_id 属性作为条件 
-- 但现在 order_items 中的 order_id 是有重复的，其他的表就不知道应该添加 order_items 的哪个表项进 

-- 出现这种情况时，我们可用用多条件来进行关联
USE sql_store;

-- 给相同的表命名不同的名称
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	ON oi.order_id = oin.order_id
	AND oi.product_id = oin.product_id