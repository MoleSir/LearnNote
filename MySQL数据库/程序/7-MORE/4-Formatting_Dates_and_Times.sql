-- 格式化日期和时间
-- MySQL 的时间表示 ： '2019-02-12'

-- m、d、y 分别代表月、日、年，小写的话就只是数值，并且年份只有后两位
SELECT DATE_FORMAT(NOW(), 'year: %y, month %m, day: %d');
-- 大小是字符串形式，年份完整
SELECT DATE_FORMAT(NOW(), 'year: %Y, month %M, day: %D');
-- dev.mysql.com 有完整格式化形式

-- 时间格式化
SELECT TIME_FORMAT(NOW(), '%H:%i:%S,%p');