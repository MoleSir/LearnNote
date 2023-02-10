# 存储过程与函数

**存储过程** `Stored Procedure` 是一段 SQL 代码，类似编程语言中的函数；



## 创建存储过程

创建存储过程语法：

````mysql
DELIMTER 某个符号
CREATE PROCEDURE 存储过程名称 ( 参数 ) 
BEGIN
函数体
END 某个符号
DELIMTER ;
````

- `DELIMTER` ：修改默认分隔符 `;` 为某个符号，一般为 `$$`；最后还需要修改回来；

    如果不改，MySQL 会认为函数体中的 ; 是语句（暂时这样理解 ），改了以后就直接认为是一个字符，到使用的时候把这段代码复制到使用的地方，`;` 也会根据复制；

- 函数体中的每一句语句都需要增加 `;`，尽管只有一句；

例如：

````mysql
USE sql_invoicing;
DELIMITER &&
CREATE PROCEDURE get_clients()
BEGIN
	-- 函数体中每个语句用 ; 结尾，就算只有一个语句也需要
	SELECT * FROM sql_invoicing.clients;
END &&
-- 最后再改回 ;
DELIMITER ;
````

创建后，与视图类似，不会有结果输出，但是在数据库的 Stored Procedure 中会多出一个 `get_client` 过程；

点击就可以运行这个过程；

或者写代码执行，可以使用其他编程语言调用存储过程：

```mysql
CALL sql_invoicing.get_clients()
```

使用 `CALL` 关键字执行；

> PS：手写代码创建过程比较麻烦，在 MySQLWorkBench 中可以直接创建，在数据库的 Stored Procedure 右键点击 Create Stored Procedure 会出现一个界面，MySQL 已经写好了框架，我们只有实现函数体就好；



## 删除过程

与删除视图一样，使用 `DROP` 关键字：

````mysql
USE sql_invoicing;
DROP PROCEDURE get_clients;
````

删除后再次执行删除会报错，因为找不到这个过程，可以使用 `IF EXISTS`：

````mysql
DROP PROCEDURE IF EXISTS get_clients;
````



## 带参数的过程

给过程加参数：

在括号中写参数，参数名称后指定类型（like python），例如：

````mysql
DELIMITER $$
CREATE PROCEDURE get_clients_by_state
(
	state CHAR(2)
) 
BEGIN
	SELECT * 
    -- 防止重名，给表格起个名
    FROM clients c
    WHERE c.state = state;
END $$
DELIMITER ;
````

> PS：
>
> - `CAHR(n)` n 个字符的字符串；
> - `VARCHAR` 任意长度的字符串；
> - `INT` 整数；
> - `...`



## 默认值参数

MySQL 并没有像其他编程语言的那样直接支持默认参数的语法，那可以在进入过程时先判断；

例如：传入 NULL，在过程中判断是不是 NULL，是的话给默认值，但执行过程时，参数不能空着，空着会报错：

````mysql
DELIMITER $$
CREATE PROCEDURE get_clients_by_state
(
	state CHAR(2)
)
BEGIN
    IF state IS NULL THEN 
		SET state = 'CA';
	END IF;
	SELECT * 
    FROM clients c
    WHERE c.state = state;
END $$
DELIMITER ;
````

执行 `CALL get_clients_by_state(NULL) `；

其中出现了 `IF` 语句，基本语法为：

````mysql
IF 条件 THEN
语句（每个语句都要加 ;）
ELSE 
语句（每个语句都要加 ;）
END IF;
````

执行逻辑与其他语言相同；

所以这个例子中，如果输入 `NULL`，`state` 默认为 `'CA'`； 



## 参数验证

可以对参入的参数使用 `IF` 语句进行验证，比如这里不允许 `payment_amount` 小于等于 0：

````mysql
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
````

其中涉及到异常的处理，在注释中给出；

那么如果调用过程传入了负数：

````mysql
CALL make_payment(2, -100, '2019-01-01');
````

会报错；



## 输出参数

在 MySQL 中，过程是没有返回值的，只能打印出信息，如果希望过程返回出结果，就需要使用传出参数（C# 中也有这样的概念）；

基本语法就是在参数列表中参数之前加上 `OUT` 关键字：

````mysql
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
````

然后在过程中，使用 `SELECT INTO` 语句，将查询到的结果不显示，而是放入到两个传出参数中；

调用含有传出参数的过程需要定义变量，基本语法为：

````mysql
SET @变量名称 = 值 
````

再把变量作为传出参数的实参；

````mysql
SET @invoices_count = 0;
SET @invoices_count = 0;
CALL get_unpaid_invoices_for_client(2, invoices_count, invoices_count);
````

之后两个参数中就保存着计算结果；



## 变量

在传出参数中使用了变量，这是一种 User or session variables，在整个对话过程存在，用户断开连接后就释放；可以类比 C 中的全局变量；

还有一种  Local variable 变量在过程中定义，过程执行完毕后释放，类比函数中的局部变量；

定义方式为：

```mysql
声明变量 DECLARE 变量名称 变量类型 (DEFAULT 值)
```

PS：可以不指定默认值，所以 `DEFAULT 值` 打了括号；

使用  Local variable：

````mysql
USE sql_invoicing;
DELIMITER $$
CREATE PROCEDURE get_risk_factor()
BEGIN
	-- rick_factor = invoices_total / invoices_count * 5
    -- 声明变量 DECLARE 变量名称 变量类型 (DEFAULT 值)
    DECLARE rick_factor DECIMAL(9, 2) DEFAULT 0; 
    DECLARE invoices_total DECIMAL(9, 2);
    DECLARE invoices_count INT;
	
    -- 不显示，保存到变量中
    SELECT COUNT(*), SUM(invoice_total)
    INTO invoices_count, invoices_total
    FROM invoices;
    
    SET rick_factor = invoices_total / invoices_count * 5;
    
    -- 显示
    SELECT rick_factor;
END$$
DELIMITER ;
````

其中还是使用了 `SELECT INTO` 语句就查询结果保存到变量；

并且还有 `SET` 语句，来设置一个变量；

注意这个过程不能返回值，只是把计算结果显示出来；



## 函数

函数类似于过程，但过程没有返回值，函数一定有返回值，并且只有一个返回值，不能是多行、多列的数据；

### 创建函数

创建函数的语法与创建过程类似 ，关键字修改为 `FUNCTION`，并且在 BEGIN 前加上返回的类型（一定要写，MySQL 函数一定有返回值），还可以设置函数属性（属性可以不写），并且在函数体的最后加 `RETURN 值` 来返回计算结果；

函数的属性可以是：

- `DETERMINISTIC`：确定性属性，调用这个函数对相同的输入总是有相同的输出；
- `READS SQL DATA` 表示函数中会有 SELECT 语句来读取数据；
- ......

````mysql
USE sql_invoicing;
DELIMITER $$
CREATE FUNCTION get_rick_factor_with_id
(
	client_id INT
)
-- 返回类型
RETURNS INTEGER
READS SQL DATA
-- ...
BEGIN
    DECLARE rick_factor DECIMAL(9, 2) DEFAULT 0; 
    DECLARE invoices_total DECIMAL(9, 2);
    DECLARE invoices_count INT;
	
    -- 不显示，保存到变量中
    SELECT COUNT(*), SUM(invoice_total)
    INTO invoices_count, invoices_total
    FROM invoices i
    WHERE i.client_id = client_id;
    
    SET rick_factor = invoices_total / invoices_count * 5;
    
    -- 返回语句 
    RETURN IFNULL(rick_factor, 0);
END$$
````

同样，函数创建后保存在数据库的 Function 栏中，和过程、视图都一样；

### 使用函数

可以像 MySQL 内置的函数一样使用自定义函数：

````mysql
SELECT 
	client_id,
    name,
    get_rick_factor_with_id(client_id) AS rick_factor
FROM clients;
````

### 删除函数

`DROP` 关键字：

````mysql
DROP FUNCTION IF EXISTS get_rick_factor_with_id;
````

