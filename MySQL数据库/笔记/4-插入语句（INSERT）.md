# 插入语句 INSERT

## 列的属性

每个表的每个列都有一些属性，在 MySQL 工作台中，可以查看每个列的属性；

- PK：标志此列是否为表的主键，主键不可以重复；
- NN：标志此列是否必须，如果非必须的属性可以填入 NULL；
- Default Value：此列的默认值，在插入元素时，可以使用 `DEFAULT` 关键字，MySQL 会直接帮我们填入此列的默认值，如果一个列是非必要的，必须给其一个默认值，我们不填，MySQL 就会自动帮我们填入；
- AI：自动赋值属性，如果某列有了这个属性（通常是一个表的主键），我们插入新行时，如果没有给其赋值，或者使用 `DEFAULT` 关键字，MySQL 会自动按照升序对这个列赋值，比如一个id有 AI 属性，我们插入第一行，MySQL 给id赋值为1，插入第二行，给其赋值为2，以此类推；

还有更多的属性，之后遇到再说；

---



## INSERT 语句

向一个表格中插入新的行使用 `INSERT` 语句；

### 单行插入

单行插入时，`INSERT` 的基本语法为：

````mysql
INSERT INTO 要插入的表格
VALUES (值1, 值2, 值3...)
````

- `INSERT INTO`：后写需要插入的是哪个表格；
- `VALUES` 写上一个括号，括号里面写要插入的新行的各个属性，按照表格的属性顺序给出值，如果某些列有默认值，可以用 DEFAULT 代替；

比如这里向 customers 表插入新行；

````mysql
INSERT INTO customers
VALUES (
	DEFAULT,  -- > 主键，customer_id，具有 AI 属性，让 MySQL 帮我们写
	'Ye', 	  -- > first_name
    'Cheng',  -- > last_name
    '2002-07-16',  -- > birth_date
    DEFAULT, -- 或者直接 NULL --> phone，非必要属性，默认值就是 NULL
    'China',	-- > address
    'NingDe',	-- > city
    'SN',		-- > status
    DEFAULT);   -- > 分数，有默认值 0
````

这样我们会写比较多的 `DEFAULT`，MySQL 允许我们指定插入新行时的列顺序，要在表格名称后写上填入的属性：

````mysql
INSERT INTO 表格名称 (属性1, 属性2, 属性3...)
VALUES (值1, 值2, 值3)
````

需要注意，属性与值要一一对应。

有了这个语法我们就可以在表格名称后，不选择那写有默认值的属性，不用写那么多 `DEFAULT`，MySQL 会自动帮助我们填入默认值；

````mysql
INSERT INTO customers (
	first_name,
    last_name,
    birth_date,
    address,
    city,
    state)
VALUES(
	'Xu', 
    'XuTing', 
    '2002-02-14', 
    'China',
    'NingDe',
    'SN');
````

---

### 多行插入

多行插入的语法跟单行类似，只需要在 `VALUES` 后写多个括号，每个括号标识要插入的新行：

````mysql
INSERT INTO products (name, quantity_in_stock, unit_price)
VALUES ('Product1', 10, 1.95),
	   ('Product2', 11, 1.95),
	   ('Product3', 12, 1.95)
````

---

### 插入分层数据

有时若干个表之间存在着关系，比如：

orders 表保存每笔订单的信息， 有一个 order_id 属性，但每个订单都买了些什么，这些信息保存在了 order_items 表里。那里记录了每笔订单里面都有什么产品，所以在 order_items 里面，也有一个 order_id 属性，并且这个属性不一定要独立，因为每个订单可以有多个产品与 orders 里的对应，我们可以将两个表格 JOIN 起来；  

那么如果我们向 orders 插入一个新行，应该也要向 order_items 插入若干行（行数取决于这笔订单的产品数量）

这看起来没什么，只要执行多次 `INSERT`，向两个表格插入数据。但问题是，在 orders 中，order_id 是 MySQL 按顺序自己填入的，我们并不知道其具体的值；

那么如何在向 order_items 插入行时填入 order_id 信息呢？

这就需要使用到： `LAST_INSERT_ID()`，它保存最近一个 MySQL 为我们填入的值；

那么实现就很简单：

````mysql
-- 先向 orders 插入数据
INSERT INTO orders (customer_id, order_date, status)
VALUES (1, '2019-01-02', 1);

-- 再向 order_items 插入,使用 LAST_INSERT_ID() 函数获取行号
INSERT INTO order_items
VALUE
	(LAST_INSERT_ID(), 1, 1, 2.95),
    (LAST_INSERT_ID(), 2, 1, 3.98)
````

---

### 插入表格

除了插入新行，也可以插入一些已经存在的表格，只要我们保证 `INSERT INTO 表格名称` 后的那种表格的列要与原表格匹配即可，之后的那个表格可以由 `JOIN` 、`SELECT` 等语句得到，例如：

````mysql
INSERT INTO order_archived
-- SELECT 得到一张表，插入到上面的表后
SELECT * -- 这里选择所有，要跟上面选择插入到属性对应
FROM orders
WHERE order_date < '2019-01-01';
````

---



## CREATE TABLE 语句

`CREATE TABLE` 语句允许我们用一张已经存在的表格创建新表，基本语法为：

````mysql
CREATE TABLE 新表名称 AS 
一张表格
````

注意这里的一张表格不是指就直接填入一张已经存在的表格名称，而是要经过我们之前学习的那么多 `SELECT`、`JOIN` 等语句从已经有的表格中获得到的一张新表格；

---

### 拷贝整张表格

比如，我们可以使用 `SELECT * FROM 表格名` 获取整张表后创建新表格：

````mysql
CREATE TABLE order_archived AS 
SELECT * 
FROM orders;
````

需要注意，创建得到的表只是内容跟旧表格一样，表格的属性是不会复制的；

---

### 拷贝部分表格

已经提过，这里的一张表格的范围很宽泛，刚刚的例子是取整张表，那么我们也可以过 `WHERE` 筛选出来一些：

比如把所有日期小于 19 年的订单复制到新表：

````mysql
CREATE TABLE order_archived AS 
SELECT *
FROM orders
WHERE order_date < '2019-01-01';
````

---



## UPDATE 语句

`UPDATE ` 语句允许我们修改已经存在的表格信息；

---

### 更新单行

更新单行的 `UPDATE` 的基本语法如下：

````mysql
UPDATE 表格名称
SET 属性1 = xxx, 属性2 = yyy
WHERE 匹配条件
````

- `UPDATE` 后加上要修改的表格名称；
- `SET` 后就是如何修改表格属性，表示希望把什么属性改为什么值，等号右边的值可以是字面量，也可以是属性之间组成的表达式，比如 `price = 2 * price`，把原来的价格翻倍；
- `WHERE` 后加匹配条件，确定是修改哪一行；

比如，把 invoices 表格中 invoice_id 为 1 的行的 payment_total 改为 10，payment_date 改为 '2019-03-01'：

````mysql
UPDATE invoices
SET payment_total = 10, payment_date = '2019-03-01'
WHERE invoice_id = 1;
````

---

### 更新多行

更新多条语句，就是把更新一条语句后的 `WHERE` 条件改了，让多行满足即可；

但在 MySQL 工作台中默认开启安全模式，不允许修改多行，需要做一些设置，找到：

 Edit  --> Rreferences --> SQL Editer --> 拉到最后，将 Safe Update 取消勾选；

比如将 invoices 表格中所有 client_id 为 3 的修改，payment_total 变为 invoice_total  的一半，payment_date 改为 due_date；

````mysql
UPDATE invoices
SET 
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
WHERE client_id = 3; -- WHRER 是可选的，如果要更新表中所有数据，不写 WHERE即可
````

WHRER 是可选的，如果要更新表中所有数据，不写 WHERE即可；

---

### 使用子查询

在 `UPDATE` 中使用 子查询，比如：

我们在 invoices 表中只有客户的 id，没有姓名，它们的映射关系保存在 clients 中。而 id 一般都是数据库内部使用，用户一般操作都是输入名称，那么我们如何根据用户输入的名称来对 invoices 作更新操作？

就需要在 `UPDATE` 的 `WHERE` 语句中使用子查询；

---

#### 修改单行

我们先看这样的一个语句：

```mysql
SELECT client_id -- 只选择了 id 返回
FROM clients
WHERE name = 'Myworks'
```

在 clients 表格中选择了 name 是 Myworks 的行，显示器 client_id；

如果其中只有一个 name 为 Myworks，那么最后得到的结果就是一个数字；

我们可以把这一小段语句理解为一个函数，最后其返回一个数字；

回到这个例子，如果我们希望根据 client_id 来找要修改的对象，很简单：

````mysql
UPDATE invoices
SET 
	payment_total = invoice_total * 0.5,
	payment_date = due_daye
WHERE client_id = id;
````

这里的 id 就是我们要修改的客户 id；

所以我们可以直接在这个 id 的位置调用 `SELECT` 语句，让其返回客户的 id，就像刚刚那个语句一样，那么这个查询就称为子查询，所以可以这样：

````mysql
UPDATE invoices
SET
	payment_total = invoice_total * 0.5,
	payment_date = due_date
WHERE client_id = (
	SELECT client_id
	FROM clients
	WHERE name = 'Myworks'
)
````

 这样就可以根据名称 Myworks 先在 `clients` 查找，再把 id 交给 `UPDATE` 去更新；

---

#### 修改多行

刚刚我们子查询的结果只有一个 id，那么如果我们查询到的结果是两个或两个以上呢？

修改的方法很简单，因为得到的是多个数字，那么就不能用 `WHERE client_id = (num1, num2...)`

应该使用之前说过的语法糖 `IN`：`WHERE client_id IN (num1, num2)`，表示或的意思；所以只有在之前的基础上，把 `=` 改为 `IN`：

````mysql
UPDATE invoices
SET 
	payment_total = invoice_total * 0.5, 
	payment_date = due_date
-- 因为 子查询返回多个值，所以这里不能用等于，必须用 IN 
WHERE client_id IN (
    -- 最后的结果不止一个
	SELECT client_id -- 只选择了 id 返回
    FROM clients
	-- 筛选出 clients 表格中属性 state 为 'CA' 或者 'NY' 的行的 client_id 属性
    WHERE state IN ('CA', 'NY'));
````

---



## DELETE 语句

`DELETE` 语句允许我们删除已经存在的行：

````mysql
DELETE FROM 表格名
WHERE 条件
````

- `DELETE` 后加要删除数据的表格名；
- `WHERE` 后的条件可以筛选出若干行，MySQL 会把这些行删除，`WHERE` 是可选命令，不写就整个表格数据删除；

---

### 单行删除

删除 invoices 表格中 invoice_id 为 1 的行；

````mysql
-- 选择要删除的表
DELETE FROM invoices
WHERE invoice_id = 1;
````

---

### 多行删除

删除 orders 表格中，order_date 小于 2018 年的所有订单

````mysql
DELETE FROM orders
WHERE order_date < '2018-01-01';
````

---

### 使用子查询

先从 clients 表格中找到名为 Myworks 的客户，获得其 client_id 后返回给 `DELETE`；

````mysql
DELETE FROM invoices
WHERE client_id = (
	SELECT client_id
	FROM clients
	WHERE name = 'Myworks');
````

如果子查询返回多个值，把 `=` 改为 `IN`：

````mysql
DELETE FROM invoices
WHERE client_id IN (
	SELECT client_id
	FROM clients
	WHERE brith_date < '1990-02-02');
````

