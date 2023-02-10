-- 给过程加参数
-- 在括号中写参数，参数名称后指定类型，like python
-- CAHR(n) n 个字符的字符串
-- VARCHAR 任意长度的字符串
USE sql_invoicing;
-- DROP PROCEDURE IF EXISTS get_clients_by_state;
DELIMITER $$
CREATE PROCEDURE get_clients_by_state
(
	state CHAR(2)
) 
BEGIN
	SELECT * 
    -- 防止重名，给表格起个名
    FROM clients c
    WHERE c.state = state;
END $$
DELIMITER ;


-- 调用
CALL get_clients_by_state('CA')