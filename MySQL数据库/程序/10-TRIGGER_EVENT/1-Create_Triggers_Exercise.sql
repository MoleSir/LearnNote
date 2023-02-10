-- 练习创建触发器
USE sql_invoicing;
DELIMITER $$
CREATE TRIGGER payments_after_delete
	AFTER DELETE ON payments
	FOR EACH ROW
BEGIN
	UPDATE invoices
    SET payment_total = payment_total - OLD.amount
    WHERE invoice_id = OLD.invoice_id;
END$$
DELIMITER ;

-- 删除一行
DELETE
FROM payments
WHERE payment_id = 10;