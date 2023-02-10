# BETWEEN 的使用

# 与 IN 类型，BETWEEN 只是一个语法糖
# 选出得分在 1000 活 3000 的
SELECT *
FROM customers
WHERE points >= 1000 AND points <= 3000;

# 使用 BETWEEN 
SELECT *
FROM customers
WHERE points BETWEEN 1000 AND 3000;