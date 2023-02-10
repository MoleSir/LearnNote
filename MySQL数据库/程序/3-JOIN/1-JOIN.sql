USE sql_store;

-- 有时我们希望在多张表格中查找信息，可以使用 JOIN 语句 
-- JOIN 表格名称 ON 条件
-- 因为两张表格没有关系，MySQL 不知道如何把两张表的行对应起来
-- 这是就需要写 ON 之后的条件，比如下面的例子中，
-- 我们希望 MySQL 选出 orders 表格中的所有数据加入到 customers 表中
-- 依据就是 orders 的 customer_id 属性与 customers 的 customer_id 属性相同的表项为同一行
-- 先出现 orders 的属性，再是 customers 的属性
SELECT *
FROM orders
JOIN customers ON orders.customer_id = customers.customer_id;

-- 给表格其别名 FROM orders o，之后可以用 o 代替 orders
-- 可以选择需要显示的属性，如果两种表有重名的属性，需要用表格名.属性名称给出
SELECT order_id, orders.customer_id, first_name, last_name
FROM orders o
-- 用 c 代替 customers
JOIN customers c
ON o.customer_id = c.customer_id