# 使用 ORDER BY 排序，如果不加的话，查询到的项会以这张表设置好的主键列排序

# 以 first_name 排序，默认为升序 a,b,c,,,
SELECT *
FROM customers
ORDER BY first_name;

# 加上 DESC 设置为降序
SELECT *
FROM customers
ORDER BY first_name DESC;

# 可以设置多个排序依据，是有顺序的，如果第一个属性相同，就按照第二个属性排序，依次类推
# 先按 state 排序，如果 state 相同再按 first_name 排序
SELECT *
FROM customers
ORDER BY state, first_name;

# 对多个排序依据，需要哪个是降序就在哪个后加 desc
# 先按 state 降序排序，如果 state 相同再按 first_name 排序
SELECT *
FROM customers
ORDER BY state DESC, first_name;

# 在 MySQL 中，即使没有被 SELECT 的属性也可以作为排序依据
