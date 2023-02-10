# IN 的使用
# 当我们对同一个属性进行多次或筛选，比如：
USE sql_store;

SELECT * 
FROM customers
WHERE state = 'VA' OR state = 'FL' OR state = 'GA';

# 这样看起来不太简洁，可以使用 IN
SELECT * 
FROM customers
WHERE state IN ('VA', 'FL', 'GA');

# 有 IN 也有 NOT IN，其代表一个也不是
SELECT * 
FROM customers
WHERE state NOT IN ('VA', 'FL', 'GA');