############## 练习 LIKE ###############
## 1. 获取地址包含 trail 或者 avenue 的顾客
SELECT * 
FROM customers
WHERE (address LIKE '%trail%') OR (address LIKE '%avenue%');


## 2. 获取手机号以 9 结尾的顾客 
SELECT * 
FROM customers
WHERE phone LIKE '%9';