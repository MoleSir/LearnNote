-- ---- 交叉连练习 -------
-- 将 shippers 与 products 交叉连接
SELECT * 
FROM shippers s
CROSS JOIN products p
ORDER BY s.name;

SELECT * 
FROM shippers s, products p
ORDER BY s.name;