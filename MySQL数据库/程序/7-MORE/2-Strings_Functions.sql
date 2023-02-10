-- 字符串函数

-- 获取长度
SELECT LENGTH('sky');

-- 小写转换大写
SELECT UPPER('key');

-- 大写转小写
SELECT LOWER('KEEEEE');

-- 去除字符串中的 ' '
-- 去左侧的 ' '
SELECT LTRIM('    YC');
-- 去右侧
SELECT RTRIM('TC     '); 
-- 去掉所有的
SELECT TRIM('   dsdsds   ');

-- 取前几个字符
SELECT LEFT('yechenhhhhhh', 4);
-- 取后几个字符
SELECT RIGHT('dasdasdas', 4);
-- 取出指定位置，指定长度的子串: 从 2 开始的 5 个字符，下标从 1 开始 
SELECT SUBSTRING('yeyeyeyeyeyeyey', 2, 5);
-- 最后一个参数不写，一直取到最后
SELECT SUBSTRING('ffffffffffffffff', 3);

-- 在字符串中搜索某个字符第一次出现的位置，找不到返回 0，下标从 1 开始，不区分大小写 
SELECT LOCATE('n', 'ASDFGHJJKLL');
-- 也可以搜索字串
SELECT LOCATE('YeChen', 'I AM YECHEN');

-- 替代字符串中的指定字串
SELECT REPLACE('Kingergarten', 'garten', 'GGGGG');

-- 串联字符串，参数个数没有限制
SELECT CONCAT('first', 'last');

USE sql_store;
SELECT CONCAT(first_name, ' ', last_name) AS full_name
FROM customers;
