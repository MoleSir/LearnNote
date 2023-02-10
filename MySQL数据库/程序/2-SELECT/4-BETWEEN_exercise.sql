############# 练习 BETWEEN ############
# 获得生日在 '1990-01-01' 与 '2000-01-01' 之间的 
SELECT * 
FROM customers
WHERE brith_date BETWEEN '1990-01-01' AND '2000-01-01';