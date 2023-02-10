# 触发器与事件

## 触发器

触发器是在插入、更新和删除语句前后自动执行的 SQL 代码，比如在支付表中增加一项，就需要保证发票表里面付款总额也得更新，可以创建一个触发器来自动完成；

### 创建触发器

创建触发器的语法与创建过程、函数很类型，都要改变分隔符，基本语法：

````mysql
DELIMITER $$
CREATE TRIGGER 触发器名称 
	AFTER / BEFORE 某个操作 ON 表格名称
	FOR EACH ROE
BEGIN
	触发器主体
END $$
DELIMITER ;
````

- 触发器的名称最好遵循规范：先指出操作的表、之后是在操作表格之前还是之后，最后是触发的操作；

    比如 `payments_after_insert` 代表在对 payments 表进行 insert 操作之后执行的触发器；

- `AFTER / BEFORE` 选一个，向 MySQL 指明在之前触发还是之后；

- `某个操作` 写一个操作：`INSERT` 、`DELETE` 等，向 MySQL 指明什么操作才会触发；

- `表格名称`：操作什么表格会引发触发器；

- `FOR EACH ROE`：每插入一行执行一次；

- `触发器主体` ：所有语句用 `;` 结尾；

举例：

````mysql
USE sql_invoicing;
DELIMITER $$
CREATE TRIGGER payments_after_insert 
	AFTER INSERT ON payments
	FOR EACH ROW
BEGIN
    UPDATE invoices
    SET payment_total = payment_total + NEW.amount
    WHERE invoice_id = NEW.invoice_id;
END $$
DELIMITER ;
````

创建一个名为 `payments_after_insert` 的触发器，在对 payments 表进入插入后执行；

其中的 `NEW` 表示刚刚插入的那一行数据，如果是删除，`OLD` 表示刚刚删除的那一行数据；

配合 `NEW` 用 `.` 取出刚刚插入的表项的各个属性值；

### 查看触发器

不能通过 workbench 查看，只能使用命令：

```mysql
SHOW TRIGGERS;
```

显示当前数据库的所有触发器；

````mysql
SHOW TRIGGERS LIKE 'payments%'
````

以 `payments` 开头的触发器，如果规范命名的话，就方便查找；

### 删除触发器

典中典

````mysql
DROP TRIGGER IF EXISTS payments_after_insert;
````

### 触发器审计

使用触发器进行审计：有人操作了表，使用一个触发器记录这个动作，方便之后查看；

比如，在数据库中的 `payments_audit` 表，记录了对 `payments` 表修改的时间、操作等信息，还可以保存删除的数据，方便日后的修复；

给[创建触发器]()中的例子加上审计功能：

````mysql
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
````

之后对表插入数据后，MySQL 会自动记录信息；



## 事件

事件是根据计划执行的 SQL 代码；

可以设置事件按照某个规则执行，比如每天 10 点执行一次、每年执行一次等；

实现自动化维护、自动生成汇总表等；

使用事件之前需要打开事件调度器，使用 `SHOW VARIABLES` 查看 MySQL 的系统变量，加上通配符可以更快寻找：

`````mysql
SHOW VARIABLES LIKE 'event%';
`````

如果 `event_scheduler` 是 `OFF`，执行命令将其开启：

````mysql
SET GLOBAL event_scheduler = ON;
````

### 创建事件

基本语法：

````mysql
DELIMITER $$
CREATE EVENT 事件名称
ON SCHEDULE
	事件调度设置
DO BEGIN
	事件主体
END$$
DELIMITER ;
````

- `事件名称` ：需要满足命名规范，最好以事件的执行间隔开头方便查找；

- `事件调度设置` ：在这里设置事件调度的时机：

    - 运行一次：`AT 一个时刻 ` ，在这个时刻运行事件；

        比如 `AT '2019-05-01'`  -> 在 2019-05-01 这天执行一次；

    - 间断执行：`EVERY 一段时间`，每个一段时间执行一次事件；

        比如 `EVERY 1 YEAR` -> 每隔一年执行一次；

        还可以在后面加上起始时间与终止时间：

        ```mysql
        EVERY 1 YEAR STARTS '2019-01-01' ENDS '2029-01-01'
        ```

- `事件主体`：所有语句用 `;` 结尾；

例如：

````mysql
DELIMITER $$
CREATE EVENT yearly_delete_stale_audit_rows
ON SCHEDULE 
    EVERY 1 YEAR STARTS '2019-01-01' ENDS '2029-01-01'
DO BEGIN
    DELETE FROM payment_aduit
    WHERE action_date < NOW() - INTERVAL 1 YEAR;
END$$
DELIMITER ;
````

创建一个名为 `yearly_delete_stale_audit_rows` 的事件，从 '2019-01-01' 到 '2029-01-01' 每隔一年执行一次；

### 查看事件

````mysql
SHOW EVENTS;
-- 加上通配符快速查找
SHOW EVENTS LIKE 'yearly%';
````

### 删除事件

````mysql
DROP EVENT IF EXISTS yearly_delete_stale_audit_rows;
````

### 控制事件

````mysql
-- 开启事件
ALTER EVENT yearly_delete_stale_audit_rows ENABLE;
-- 关闭事件
 ALTER EVENT yearly_delete_stale_audit_rows DISABLE;
````

