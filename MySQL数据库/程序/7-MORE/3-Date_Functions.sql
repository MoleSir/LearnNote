-- 日期函数

-- 当前日期+时间
SELECT NOW();
-- 当前日期
SELECT CURDATE();
-- 当前时间
SELECT CURTIME();

-- 取出年、月、日、时、分、秒（返回的都是数值）
SELECT YEAR(NOW()), MONTH(NOW()), DAY(NOW()), HOUR(NOW()), MINUTE(NOW()), SECOND(NOW());

-- 取出月、日（返回的都是字符串）
SELECT MONTHNAME(NOW()), DAYNAME(NOW());

-- SQL 标准：取出年、月、日等
SELECT EXTRACT( YEAR FROM NOW() );