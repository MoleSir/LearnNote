-- 练习
USE sql_invoicing;
DELIMITER $$
CREATE PROCEDURE get_payments
(
	client_id INT,
    payment_method_id TINYINT
)
BEGIN
	SELECT *
    FROM payments p
    WHERE	
		-- 写 NULL 代表全部都选
		p.client_id = IFNULL(client_id, p.client_id) AND
        p.payment_method = IFNULL(payment_method_id, p.payment_method);
END$$
DELIMITER ;

CALL get_payments(5, 2)