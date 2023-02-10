-- 创建表的复制 --

-- 复制整张表
-- 这样不会复制原表格的属性
CREATE TABLE order_archived AS 
SELECT * 
FROM orders;

-- 复制一部分
-- INSERT 不仅可以插入新行
-- 还可以复制别的过来
-- 跟联合有点类型，不过这里时真的插入到一个表格中
INSERT INTO order_archived  -- 这里没有选择插入属性
-- SELECT 得到一张表，插入到上面的表后
SELECT * -- 这里选择所有，要跟上面选择插入到属性对应
FROM orders
WHERE order_date < '2019-01-01';