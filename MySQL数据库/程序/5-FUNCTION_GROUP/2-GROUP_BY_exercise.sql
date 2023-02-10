-- GROUP BY 练习 --
-- 某个日期用什么方法支付的总和
USE sql_invoicing;
SELECT 
	date,
    pm.name AS payment_method,
    SUM(amount) AS total_payment
FROM payments p
JOIN payment_methods pm
	ON p.payment_method = pm.payment_method_id
GROUP BY date, payment_method
ORDER BY date;