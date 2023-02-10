-- 参数验证
USE sql_invoicing;
DELIMITER $$
CREATE PROCEDURE make_payment
(
	invoice_id INT,
    -- 最多 9 位，小数点后 2 位的浮点数 
    payment_amount DECIMAL(9, 2),
    payment_date DATE
)
BEGIN
	-- 先用 IF 检查参数
    IF payment_amount <= 0 THEN
		-- 抛出异常，错误代码位 22003，上网搜索
		SIGNAL SQLSTATE '22003'
			-- 给出文字提示
			SET MESSAGE_TEXT = 'Invalid payment amount';
    END IF;
    
	UPDATE invoices i
    SET
		i.payment_total = payment_amount,
        i.payment_date = payment_date
	WHERE i.invoice_id = invoice_id;
END$$
DELIMITER ;

-- 报错
CALL make_payment(2, -100, '2019-01-01');