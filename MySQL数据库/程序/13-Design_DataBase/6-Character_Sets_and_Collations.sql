-- 字符集和排序规则
-- 字符集是每个字符映射到数字的表
-- 显示字符集
SHOW CHARSET;
-- MySQL 中 CHAR(10) 是十个字符，不是 10 个字节
-- 必要时更改 MySQL 中的字符集，可以节省空间
-- 在创建数据库时设置字符集
CREATE DATABASE db_name
	CHARACTER SET latin1;
-- 对已经创建的修改
ALTER DATABASE db_name
	CHARACTER SET latin2;