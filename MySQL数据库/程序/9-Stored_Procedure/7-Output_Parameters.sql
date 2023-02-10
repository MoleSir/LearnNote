-- 输出参数
USE sql_invoicing;
DELIMITER $$
CREATE PROCEDURE get_unpaid_invoices_for_client
(
	client_id INT,
    -- 加上 OUT 表示输出参数
    OUT invoices_count INT,
	OUT invoices_total DECIMAL(9, 2)
)
BEGIN
	SELECT COUNT(*) , SUM(invoice_total)
    -- SELECT *** INTO ***
    INTO invoices_count, invoices_total
    FROM invoices i
    WHERE i.client_id = client_id AND
		payment_total = 0;
END$$
DELIMITER ;

CALL get_unpaid_invoices_for_client(3)