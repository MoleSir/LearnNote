# 视图 VIEW

一般写下一个 `SELECT` 查询，得到的只是输出，而这个查询结果之后需要多次使用，没人愿意再去写一次 `SELECT` 然后使用。就像函数一样，可以使用视图将 `SELECT` 的结果保存，供之后直接调用；



## 创建视图 

在 `SELECT` 前写 `CREATE VIEW 视图名称 AS `  即可创建一个视图：

````mysql
-- 创建名为  sales_by_client 的视图
CREATE VIEW sales_by_client AS
SELECT 
	c.client_id,
    c.name,
    SUM(invoice_total) AS total_sales
FROM clients c
JOIN invoices USING (client_id)
GROUP BY client_id, name;
````

创建视图对象后，查询结果不会显示，而视图会出现在数据库的视图面板下，可以把这个视图当作一个新的数据表来使用：

````mysql
-- 像表格一样使用视图
SELECT *
FROM sales_by_client
ORDER BY total_sales 
````



## 修改或者删除视图

使用创建视图 CREATE VIEW 只能执行一次。如果发现写的视图查询是错的，就需要修改，但是不可以在原来的代码基础上改了再执行，会报 “视图已经创建的” 错；

需要使用其他方式

### 先删后改

可以先将视图删除，使用 `DROP VIEW 视图名称`：

````mysql
DROP VIEW sales_by_client;
````

再修改源码，执行修改后的代码；

### `REPLACE` 关键字

使用 `REPLACE` 关键字，在 `Create` 后加 `OR REPLACE`：

````mysql
USE sql_invoicing;
CREATE OR REPLACE VIEW clients_balance AS 
SELECT 
	c.client_id,
    c.name,
    SUM(invoice_total - payment_total) AS balance
FROM clients cclients_balanceclients_balance
JOIN invoices i USING (client_id)
GROUP BY client_id, name;
````

这样这段代码就可以修改后直接执行；

### 在视图窗口修改

视图并不会包含数据，只是一段代码，可以把源码保存，需要使用就调用，这是最好的方式，可以与别人共享；

点击视图的扳手按钮，可以看到视图的源码，MySQL 在我们写的基础上再添加了一些东西，特别是其将属性名称、表名称都加上 ``，防止名称与关键字冲突；

 所以可以直接在视图窗口修改视图，但是不推荐；



## 可更新视图 

[创建视图]()的代码中，在查询语句 `SELECT FROM` 后使用了视图，仅仅选择其中的数据，没有对其修改；

而视图在某些情况下可以进行 `INSERT、UPDATE、DELETE` 等修改语句；

可以进行这些修改操作的视图称为可**更新视图 `update view`；**

可更新视图必须不包含：`DISTNCT`、Aggregate 聚合函数、`GROUP BY / HAVING` 与 `UNION`；不包含上述所有操作的视图称为可更新视图；

比如下面这个例子就是一个可更新视图：

````mysql
USE sql_invoicing;
CREATE OR REPLACE VIEW invoices_with_balance AS
SELECT   
	invoice_id,
    number,
    client_id,
    invoice_total,
    payment_total,
    invoice_total - payment_total AS balance,
    invoice_date,
    due_date,
    payment_date
FROM invoices
WHERE (invoice_total - payment_total) > 0
WITH CHECK OPTION;
````

可以对其修改：

````mysql
DELETE FROM invoices_with_balance
WHERE invoice_id = 1;

UPDATE invoices_with_balance
SET due_date = DATE_ADD(due_date, INTERVAL 2 DAY)
WHERE invoice_id = 2;
````

并且修改视图后，原来的数据也发生了改变，再次说明，视图没有数据，只是一个查询，修改视图会影响原数据；



## WITH CHECK OPTION 关键字

使用下面的代码创建视图：

````mysql
USE sql_invoicing;
CREATE OR REPLACE VIEW invoices_with_balance AS
SELECT   
	invoice_id,
    number,
    client_id,
    invoice_total,
    payment_total,
    invoice_total - payment_total AS balance,
    invoice_date,
    due_date,
    payment_date
FROM invoices
WHERE (invoice_total - payment_total) > 0
WITH CHECK OPTION;
````

可以看到，`WHERE` 语句要求 `invoice_total > payment_total` 的项才被选中；

如果现在执行这样的更改：

````mysql
UPDATE invoices_with_balance
SET invoice_total = payment_total
WHERE invoice_id = 2;
````

执行完后，看起来只是把 `invoice_id = 2` 这行（简称 2 号）的 `invoice_total = payment_total`，但是视图中这个项却消失了；

这是因为更新了视图，先修改了 2 号的 `invoice_total` 属性，然后 MySQL 会再去执行产生 `invoices_with_balance` 视图的代码，在那里没有将 `invoice_total - payment_total < 0` 的项加入视图，所以 2 号也不加入，导致 2 号被删除；

可以得知，视图果然只是一段代码，使用的时候会创建，并不是真正存在数据，并且修改或删除视图还会对原数据造成影响；

PS：在这个例子中，2 号没有被删除，但是对它的修改确实发生了

如果创建视图时，在最后加上  `WITH CHECK OPTION`，当视图的某行可能被删除时，会报错：

````mysql
USE sql_invoicing;
CREATE OR REPLACE VIEW invoices_with_balance AS
SELECT   
	invoice_id,
    number,
    client_id,
    invoice_total,
    payment_total,
    invoice_total - payment_total AS balance,
    invoice_date,
    due_date,
    payment_date
FROM invoices
WHERE (invoice_total - payment_total) > 0
// 相比上面多加了行这个
WITH CHECK OPTION;
````

使用 `WITH CHECK OPTION` 再次创建视图，执行下面的程序报错，更改不会执行：

````mysql
UPDATE invoices_with_balance
SET invoice_total = payment_total
WHERE invoice_id = 3;
````

总是，创建视图时加上 `WITH CHECK OPTION`，可以避免之后对视图修改时不小心删除了某行；