-- 事件是根据计划执行的 SQL 代码
-- 可以设置事件按照某个规则执行，比如每天 10 点执行一次这样
-- 可以自动化维护

-- 使用事件之前需要打开事件调度器
-- 使用 SHOW VARIABLES 查看 MySQL 的系统变量
SHOW VARIABLES LIKE 'event%';
-- 需要将这个变量改为 ON 
SET GLOBAL event_scheduler = ON;

-- 创建事件
DELIMITER $$
-- 注意命名规范，以间隔开头，方便查找
CREATE EVENT yearly_delete_stale_audit_rows
-- 设置事件的调度
ON SCHEDULE 
	-- 调度一次  AT '2019-05-01' （AT + 一个时刻）
    -- 调度多次: EVERY + 一段时间， 后面还可以跟上起始时间与终止时间，但不是必要的
    EVERY 1 YEAR STARTS '2019-01-01' ENDS '2029-01-01'
DO BEGIN
	-- 事件体
    DELETE FROM payment_aduit
    -- 删除时间超过一年的审计
    WHERE action_date < NOW() - INTERVAL 1 YEAR; -- DATE_SUB(NOW(), INTERVAL 1 YEAR)
END$$
DELIMITER ;

-- 查看事件
USE sql_invoicing;
SHOW EVENTS;
SHOW EVENTS LIKE 'yearly%';

-- 删除
DROP EVENT IF EXISTS yearly_delete_stale_audit_rows;

-- 控制事件
-- 开启事件
ALTER EVENT yearly_delete_stale_audit_rows ENABLE;
-- 关闭事件
 ALTER EVENT yearly_delete_stale_audit_rows DISABLE;