############# WHERE #############
USE sql_store;

# 比较运算符：各种都可以使用 >, >=, <, <=, =, <>
# 其中比较特殊的是等于于不等于 = / <> 于一般编程语言不一样
# 筛选出 points属性大于 3000
SELECT *
FROM customers
WHERE points > 3000; 

# 筛选出 state 为 VA 的
SELECT *
FROM customers
# 这是一个字符串的类型，使用单引号或者双引号，不区分大小写，写 'va' 也是一样的 
WHERE state = 'VA';

# 筛选出 state 不为 VA 的
SELECT *
FROM customers
WHERE state <> 'VA';

# 筛选日期，MySQL 中有日期的标志表达形式： '年-月-日'，可以直接使用比较运算法比较
# 筛选出 birth_date 大于 1990-01-01 的
SELECT *
FROM customers
WHERE birth_date > '1990-01-01';


# 逻辑运算符，可以实现多个条件查询：AND OR NOT
# 筛选出 birth_date 大于 1990-01-01 并且 得分大于 1000 的
SELECT *
FROM customers
WHERE birth_date > '1990-01-01' AND points > 1000;

# 筛选出 birth_date 大于 1990-01-01 或者 得分大于 1000 的
SELECT *
FROM customers
WHERE birth_date > '1990-01-01' OR points > 1000;

# OR AND 一起使用时，先计算 AND，再计算 OR，可以用 () 来明确指定
# 筛选出 birth_date 大于 1990-01-01 或者 （得分大于 1000 的 并且 state 为 VA 的）
SELECT *
FROM customers
WHERE birth_date > '1990-01-01' OR ( points > 1000 AND state = 'VA' );

# NOT 即为取反
# 筛选出 除了 birth_date 大于 1990-01-01 或者 得分大于 1000 的所有人
SELECT *
FROM customers
WHERE NOT ( birth_date > '1990-01-01' OR points > 1000 );


