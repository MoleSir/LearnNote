-- 触发器是在插入、更新和删除语句前后自动执行的 SQL 代码
-- 比如在支付表中增加一项，就需要保证发票表里面付款总额也得更新
-- 可以创建一个触发器来完成
USE sql_invoicing;
-- 创建触发器的语法与创建过程、函数很类型，都要改变分隔符
DELIMITER $$
-- 创建一个名称为 payments_after_insert 的触发器
CREATE TRIGGER payments_after_insert 
	-- 触发器在 ayments 表格执行 INSERT 语句后执行 
	AFTER INSERT ON payments
    -- 每插入一行执行一次
	FOR EACH ROW
BEGIN
	-- 触发器主体
    UPDATE invoices
    -- NEW 表示刚刚插入的那一行数据，如果是删除，OLD 表示刚刚删除的那一行数据
    -- 用 . 取出刚刚插入的表项的各个属性值
    SET payment_total = payment_total + NEW.amount
    WHERE invoice_id = NEW.invoice_id;
    -- 触发器中不能修改引发触发器的那个表，否则就不断触发
END $$
DELIMITER ;

-- 测试
INSERT INTO payments
VALUES (DEFAULT, 5, 3, '2019-01-01', 10, 1);