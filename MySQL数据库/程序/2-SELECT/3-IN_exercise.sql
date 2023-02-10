############ 练习 #############
-- 返回数量为 49, 38, 72 的产品
 
SELECT * 
FROM products
WHERE quantity_in_stock IN (49, 38, 72);