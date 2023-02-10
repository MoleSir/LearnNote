# 有些对象的属性会缺失，显示其为 null，可以使用 IS NULL 来获取

# 获取没有填写电话的顾客
SELECT *
FROM customers
WHERE phone IS NULL;

# 获取填写电话的顾客
SELECT *
FROM customers
WHERE phone IS NOT NULL;