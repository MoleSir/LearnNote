-- 练习创建存储过程

USE sql_invoicing;

DELIMITER $$
CREATE PROCEDURE get_invocies_with_balance()
BEGIN
	SELECT * 
	FROM invoices_with_balance
	WHERE balance > 0;
END$$
DELIMITER ;