# LIKE 的使用，作用类型正则表达式

# 选择出 last_name 以 b 开头的
# 语法：
	# WHERE 属性 LIKE 表达式
SELECT *
FROM customers
# % 代表任意字符，表示开头是 b，之后任意
WHERE last_name LIKE 'b%';

# 选择出 last_name 以 brush 开头的
SELECT *
FROM customers
WHERE last_name LIKE 'brush%';

# % 可以放置在任意位置，表示指定的字母相对位置可以为任意字符
# 选择出 last_name 存在 b 的
SELECT *
FROM customers
WHERE last_name LIKE '%b%';

# 选择出 last_name 以 y 结尾的
SELECT *
FROM customers
WHERE last_name LIKE '%y';

# % 代表任意个数的字符， '_' 代表一个字符
# 选择出 last_name 以 y 结尾的，并且长度为两个字符的
SELECT *
FROM customers
# _ y
WHERE last_name LIKE '_y';

# 选择出 last_name 以 y 结尾的，并且长度为6个字符的
SELECT *
FROM customers
# _ _ _ _ _ y
WHERE last_name LIKE '_____y';

# 选择出 last_name 以 b开头，以 y 结尾的，并且长度为6个字符的
SELECT *
FROM customers
# b _ _ _ _ y
WHERE last_name LIKE 'b____y';

# NOT LIKE
# 选择手机号不以 9 结尾的所有顾客
SELECT * 
FROM customers
WHERE phone NOT LIKE '%9';
