-- IFULL 与 COALSCE 函数 

USE sql_store;
SELECT 
	order_id,
    -- 如果 shipped_id 是 null，就给一个值为 `not assigned` 
    IFNULL(shipper_id, 'Not assigned') AS shipper
FROM orders;


USE sql_store;
SELECT 
	order_id,
    -- 如果某行 sipper_id 是空，判断这行的 comments 是不是空，如果不是，用 comments 的值替代
    -- 如果 comments 还是空，就用给出的字符串代替
    -- 可以写无限多项，总是就是从第一个往后遍历到一个不为空的填入（给定的字符串肯定不是空，最多就判断到这里，后面的写了也没有用）
    COALESCE(shipper_id, comments, 'Not assigned') AS shipper
FROM orders;


-- IFNULL 就是只有两个参数的 COALESCE 