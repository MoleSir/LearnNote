-- 带有默认参数 
USE sql_invoicing;

-- 传入 NULL，在过程中判断是不是 NULL，是的话给默认值
-- 执行过程时，参数不能空着 
DELIMITER $$
CREATE PROCEDURE get_clients_by_state
(
	state CHAR(2)
)
BEGIN
	-- 如果 state 是 null， 给其赋值
    -- IF 语法:
    -- IF 条件 THEN
	-- 语句（每个语句都要加 ;）
    -- ELSE 
    -- 语句（每个语句都要加 ;）
    -- END IF;
    IF state IS NULL THEN 
		SET state = 'CA';
	END IF;
	SELECT * 
    FROM clients c
    WHERE c.state = state;
END $$
DELIMITER ;