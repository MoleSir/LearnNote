-- 存储过程是一段 SQL 代码，类似函数 
-- 创建 存储过程 语法:
-- DELIMTER 某个符号
-- CREATE PROCEDURE 存储过程名称(参数)
-- BEGIN
-- 函数体
-- END 某个符号

-- 先指定数据库
USE sql_invoicing;
-- 通常这个符号使用 &&，用来改变分隔符，如果不改，MySQL 会认为函数体中的 ; 是语句（暂时这样理解 ）
-- 改了以后就直接认为是一个字符，到使用的时候把这段代码复制到使用的地方，; 也会根据复制
DELIMITER &&
CREATE PROCEDURE get_clients()
BEGIN
	-- 函数体中每个语句用 ; 结尾，就算只有一个语句也需要
	SELECT * FROM sql_invoicing.clients;
END &&
-- 最后再改回 ;
DELIMITER ;

-- 创建后，与视图类似，不会有结果输出，但是在数据库的 Stored Procedure 中会多出一个 get_client
-- 点击就可以运行这个过程
-- 或者写代码执行，可以使用编程语言调用存储过程
CALL sql_invoicing.get_clients()
