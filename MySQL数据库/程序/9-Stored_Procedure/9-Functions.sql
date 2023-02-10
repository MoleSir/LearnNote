-- 函数 
-- 函数只能返回一个值，不能返回多行 多列 
-- 创建过程的语法与创建函数类似 ，关键字修改为 FUNCTION，并且在 BEGIN 前加上返回的类型，还可以设置函数属性
-- 函数必须返回一个值
USE sql_invoicing;
DELIMITER $$
CREATE FUNCTION get_rick_factor_with_id
(
	client_id INT
)
-- 返回类型
RETURNS INTEGER
-- DETERMINISTIC 确定性属性，调用这个函数对相同的输入总是有相同的输出
-- DETERMINISTIC
-- READS SQL DATA 表示函数中会有 SELECT 语句来读取数据
READS SQL DATA
-- ...
BEGIN
    DECLARE rick_factor DECIMAL(9, 2) DEFAULT 0; 
    DECLARE invoices_total DECIMAL(9, 2);
    DECLARE invoices_count INT;
	
    -- 不显示，保存到变量中
    SELECT COUNT(*), SUM(invoice_total)
    INTO invoices_count, invoices_total
    FROM invoices i
    WHERE i.client_id = client_id;
    
    SET rick_factor = invoices_total / invoices_count * 5;
    
    -- 返回语句 
    RETURN IFNULL(rick_factor, 0);
END$$
DELIMITER ;

-- 使用函数 
SELECT 
	client_id,
    name,
    get_rick_factor_with_id(client_id) AS rick_factor
FROM clients;

-- 删除函数
DROP FUNCTION IF EXISTS get_rick_factor_with_id;