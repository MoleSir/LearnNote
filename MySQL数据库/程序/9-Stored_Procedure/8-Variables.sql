-- 变量
-- 语法
-- SET @变量名称 = 值 
-- 使用变量保存传出参数
-- User or session variables
-- 在整个对话过程存在，用户断开连接后就释放
SET @invoices_count = 0;

-- 还有 Local variable
-- 在计算认为中的临时变量
USE sql_invoicing;
DELIMITER $$
CREATE PROCEDURE get_risk_factor()
BEGIN
	-- rick_factor = invoices_total / invoices_count * 5
    -- 声明变量 DECLARE 变量名称 变量类型 (DEFAULT 值)
    DECLARE rick_factor DECIMAL(9, 2) DEFAULT 0; 
    DECLARE invoices_total DECIMAL(9, 2);
    DECLARE invoices_count INT;
	
    -- 不显示，保存到变量中
    SELECT COUNT(*), SUM(invoice_total)
    INTO invoices_count, invoices_total
    FROM invoices;
    
    SET rick_factor = invoices_total / invoices_count * 5;
    
    -- 显示
    SELECT rick_factor;
END$$
DELIMITER ;

CALL get_risk_factor()