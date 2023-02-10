######### 练习 REGEXP #########
USE sql_store;

## 1. first name 是 ELKA 或者 AMBUR 
SELECT *
FROM customers
WHERE first_name REGEXP 'ELKA' OR first_name REGEXP 'AMBUR';
# WHERE first_name REGEXP 'ELKA|AMBUR';

## 2. last name 以 EY 或 ON 结尾
SELECT *
FROM customers
WHERE last_name REGEXP 'EY$' OR last_name REGEXP 'ON$';
# WHERE last_name REGEXP 'EY$|ON$';

## 3. last name 以 MY 开头或者包含 SE 
SELECT *
FROM customers
WHERE last_name REGEXP '^MY' OR last_name REGEXP 'SE';
# WHERE last_name REGEXP '^MY|SE';

## 4. last name 包含 BR 或者 BU
SELECT *
FROM customers
WHERE last_name REGEXP 'B[RU]';