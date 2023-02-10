-- 使用触发器进程审计
-- 有人操作了表，使用一个触发器记录这个动作，方便之后查看
-- 比如数据库中的 payments_audit 表格，就记录了对 payments 表修改的时间、操作等信息
-- 甚至保存下删除的数据，方便日后的修复


USE sql_invoicing;

-- 给之前创建的两个触发器都加上审计功能
DROP TRIGGER IF EXISTS payments_after_insert;
DROP TRIGGER IF EXISTS payments_after_delete;

DELIMITER $$
CREATE TRIGGER payments_after_insert
	AFTER INSERT ON payments
    FOR EACH ROW
BEGIN
	UPDATE invoices
    SET payment_total = payment_total + NEW.amount
    WHERE invoice_id = NEW.invoice_id;
	
    -- 插入一条审记
    INSERT INTO payments_audit
    VALUES (NEW.client_id, NEW.date, NEW.amount, 'Insert', NOW());
END$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER payments_after_delete
	AFTER DELETE ON payments
	FOR EACH ROW
BEGIN
	UPDATE invoices
    SET payment_total = payment_total - OLD.amount
    WHERE invoice_id = OLD.invoice_id;
    
    -- 插入一条审记
    INSERT INTO payments_audit
    VALUES (OLD.client_id, OLD.date, OLD.amount, 'Delete', NOW());
END$$
DELIMITER ;
-- --------------------------------------------------


INSERT INTO payments
VALUES (DEFAULT, 5, 3, '2019-01-01', 10, 1);

DELETE 
FROM payments
WHERE payment_id = 11;
