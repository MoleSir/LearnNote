########### REGEXP 的使用 ##############
## 这是真正则表达式了，用法跟 LIKE 一样，只是匹配表达式有点不一样
USE sql_store;

# REGEXP 不需要加 % 表示匹配任意字符
# 选出 last_name 中包含 field 的顾客
SELECT *
FROM customers
WHERE last_name REGEXP 'field';

# '^' 表示以什么开头
# 选出 last_name 中以 field 开头的顾客
SELECT *
FROM customers
WHERE last_name REGEXP '^field';

# '$' 表示以什么结尾，$ 放置在字符串后
# 选出 last_name 中以 field 结尾的顾客
SELECT *
FROM customers
WHERE last_name REGEXP 'field$';

# '|' 表示或者
# 选出 last_name 中包含 field 或者 mac 的顾客，注意不要乱加空格
SELECT * 
FROM customers
WHERE last_name REGEXP 'field|mac';

# 选出 last_name 中包含 field 或者 mac 或者 rose 的顾客
SELECT * 
FROM customers
WHERE last_name REGEXP 'field|mac|rose';

# 加上 '^' 与 '$'
# 选出 last_name 中 以field开头 或者包含 mac 或者包含 rose 的顾客，注意不要乱加空格
SELECT * 
FROM customers
WHERE last_name REGEXP '^field|mac|rose';

# [] 的作用，直接看例子
# 选出 last_name 中包含 ge 或者 ie 或者 me 的顾客
SELECT *
FROM customers
WHERE last_name REGEXP '[gim]e';

# 选出 last_name 中包含 ef 或者 em 或者 eq 的顾客
SELECT *
FROM customers
WHERE last_name REGEXP 'e[fm1]';

# 选出 last_name 中包含 e之前为 a 到 h 的任意一个字符
SELECT *
FROM customers
WHERE last_name REGEXP '[a-h]e';

-- ^ beginning
-- $ end
-- | logical or
-- [abcd] 
-- [a-f]