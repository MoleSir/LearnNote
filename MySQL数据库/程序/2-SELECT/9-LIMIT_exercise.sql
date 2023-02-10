####### LIMIT 练习 ###########
## 得到 loyal 最高的三个顾客

SELECT *
FROM sql_store.customers
ORDER BY points DESC 
# LIMIT 总是放在最后 
LIMIT 3;