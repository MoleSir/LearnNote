# 连接语句 JOIN 

之前我们学习了如何使用 `SELECT` 在一张表内部筛选，显示、排序数据。但是有些时候一张表并没有完整的信息，我们希望在多张表内查询数据，并且把他们连接起来一起显示；

比如说我们有一张表格记录了顾客信息，每个顾客都会买一样东西，在顾客表中，我们用一个属性 order_id 的数字来记录某个用户买了什么，但具体这个数字代表了什么商品以及商品的信息我们不知道，这个映射关系被保存到了另一张保存商品信息的表格中。

如果我们只对顾客表使用 `SELECT` 我们最多也只能看到顾客购买商品的 order_id，这时就可用使用 `JOIN` 语句，把两张表连接起来。

MySQL 需要知道我们如何把两种不同表格的表项作为同一行显示，所以 `JOIN` 语句必须要求我们给出一个条件；拿上述的例子来说，连接顾客表与商品表的条件就是：顾客表的 order_id 属性与商品表的 id 属性相同，满足这个条件的就可用连接为同一行；

---



## JOIN 语句

`JOIN` 语句的基本语法为：

````mysql
SELECT 需要显示的属性1, 需要显示的属性2, 需要显示的属性3...
FROM 表1
JOIN 表2 ON 连接条件
````

`FROM` 之后的表与 `JOIN` 之后的表是没有顺序的，交换一下也是可以的（暂时我是这样认为）；

那么上述的例子可以这样写：

````mysql
SELECT *
FROM customers
JOIN orders ON customers.order_id = orders.order_id;
````

- 因为两个表格的 `order_id` 属性名称相同，要使用的话需要用表名取出；

我们已经知道可以用 `AS` 给属性命名，MySQL 也允许我们对表格命名，语法更简单，直接在表格后加空格再输入新名称即可，这里把表 customers 改为 c，orders 改为 o，方便书写：

````mysql
SELECT 
	c.cuustomer_id, 
	c.first_name,
    c.order_id,
    o.name
FROM customers c
JOIN orders o 
	ON c.order_id = c.order_id;
````

----



## 跨数据库 JOIN 

上述的例子中，两个表格都是处于同一个数据库中的，对不同数据库的 `JOIN` 语句也并不复杂，在使用表格之前用数据库名称引出即可：

````mysql
SELECT * 
FROM sql_store.order_items oi
JOIN sql_inventory.products p
ON oi.product_id = p.product_id
````

---



## 同一张表格 JOIN

有时我们需要连接的数据位于同一张表格，比如下面这个例子：

有一张记录员工属性的表格 empolyees，有员工编号属性 id，并且员工需要向某个人报告自己的工作，所有有报告人属性 reporter_id；

我们希望得到一张新表格，我们不是看到员工的报告人 id，而是直接可以知道其报告人名字；

这就是在同一张表格中的 `JOIN`，很显然条件就是 reporter_id 与 id 相同；

但这是同一张表格，那么就需要用到命名的办法，把同一张表格命名为不同的名称，一个逻辑上改边为报告人表格

````mysql
SELECT 
	e.id,
	e.first_name,
	m.fitst_name
-- 给表格命名为 e
FROM empolyees e
-- 给表格命名为 m，从逻辑上分出两种表格，m 代表报告人表
JOIN empolyees m
	ON e.reporter_d = m.id
````

---



## 多表 JOIN

多表格的连接也是常见的，比如这样一个例子：

有一张商品表 orders，其中有两个属性：购买人 customer_id，与商品当前状态 status_id，两个属性都是数字，购买人信息保存在 customers 表中，其有 customer_id 与购买人名字的映射关系，同时 order_statuses 表中保存各个 status_id 代表的含义；

我们希望把这三种表格连接起来，显示一个完整的、可读的商品表；

这需要多表 `JOIN`，语法也很简单，就是在完成一次 JOIN 后再增加一次：

````mysql
SELECT 需要显示的属性1, 需要显示的属性2, 需要显示的属性3...
FROM 表1
JOIN 表2 ON 连接条件1
JOIN 表3 ON 连接条件2
JOIN 表4 ON 连接条件3
...
````

那么，很明显我们希望完成两次连接：orders 与 order_statuses 的连接，orders 与 cutomers 的连接，所以这里的表1是 orders，因为上述的表1只能为 orders，因为都是跟表1连接的；两次连接的条件也很简单：

````mysql
SELECT  
	o.irders_id,
	o.name,
	c.name,
	os.status_name
FROM orders o
JOIN customers c
	ON o.customer_id = c.customer_id
JOIN order_statuses os
	ON o.status_id = os.status_id 
````

---



## 多条件 JOIN

可以在 `ON` 后写多个条件：

````mysql
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	ON oi.order_id = oin.order_id
	AND oi.product_id = oin.product_id
````

要满足 `ON` 后的条件才会被连接；

---



## OUTER JOIN 语句

### JOIN 语句的分类

之前我们使用的 JOIN 都是内连接，SQL 有两种连接方式： 

- `INNER JOIN` 内连接，不写 `INNER` 的话，默认的都是内连接；
- `OUTER JOIN` 外连接又分为左连接与右连接
    - `LEFT OUTER JOIN`，写 `LEFT JOIN` 也代表 `LEFT OUTER JOIN`；
    - `RIGHT OUTER JOIN`，写 `RIGHT JOIN` 也代表 `RIGHT OUTER JOIN`；

---

### 单表外连接

具体的区别不好描述，看一个例子：

使用内连接时，如果某些表项没有我们给定的能够条件中的属性，既为 null，这个表项不会被选中；比如 employee 的例子中，所有人除了 CEO 都有一个 reporter_id 属性， 即 CEO 的 reporter_id 是 null。那么我们使用内连接时，CEO 就不会被显示到结果中，因为他没有 report_id 属性；

````mysql
SELECT 
	e.id,
	e.first_name,
	m.fitst_name
FROM empolyees e
JOIN empolyees m
	ON e.reporter_d = m.id
````

那么如果我们希望属性为 null 的也可显示出来就需要使用外连接，使用外 `JOIN` 之前，还需要明确一下 `JOIN` 的顺序，这样才能区别出左右连接的作用：

- 写在 `FROM` 后的表格是左表，写在  `JOIN`  后的表格右表；
- 使用 `LEFT JOIN` 时，代表：不管左表的表项是否满足条件都要把其显示；
- 使用 `RIGHT JOIN` 时，代表：不管右表的表项是否满足条件都要把其显示；
- 两个表格在内连接时候谁左谁右没有差别，在外连接中就有了；

这样我们可以使用外连接修改上面的表格：

````mysql
SELECT 
	e.id,
	e.first_name,
	m.fitst_name AS reporter
LEFT FROM empolyees e
JOIN empolyees m
	ON e.reporter_d = m.id
````

这样无论 employees 表项是否满足 `e.reporter_d = m.id` 都会被显示出来，只不过 CEO 的 reporter 属性就是 null 了；

这里使用了左连接，用右连接也是可以的：

```mysql
SELECT 
	e.id,
	e.first_name,
	m.fitst_name AS reporter
RIGHT FROM empolyees m
JOIN empolyees e
	ON e.reporter_d = m.id
```

---

### 两表外连接

再来看一个两种不同表格的例子：

将 orders 连接到 customers 中，条件是二者的 customer_id 相同。customers 保存 1-10 号 customer_id 的十位顾客，orders 中的 customer_id 代表某个 order 属于哪个 customers。显然，customers 中的 customer_id 不重复，而 orders 的 customer_id 重复了，并且有遗漏，其中 1、3、4、9 号顾客没有订单

内 `JOIN`： 结果中没有 1, 3, 4, 9 顾客：

````mysql
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM customers c
JOIN orders o
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id;
````

`LEFT JOIN`：左JOIN，保证左表格 customers 的每一项都出现

````mysql
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM customers c
LEFT JOIN orders o
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id;
````

`RIGHT JOIN`： 右JOIN，保证右表格 customers 的每一项都出现

````mysql
USE sql_store;
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id
FROM orders o
RIGHT JOIN customers c
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id
````

---

### 多表外连接

按照之前多表连接的语法，并且注意左右表的位置，可以完成多表外连接，并且每个 `JOIN` 语句是独立的，可以一个外一个内；

下面就 customers 表格与 orders 还有 shippers 连接：

````mysql
SELECT 
	c.customer_id,
    c.first_name,
    o.order_id,
    sh.name AS shapper
-- FROM 后的是左表
FROM customers c
-- 先进行一次 cutomers 与 orders 的左 JOIN，要求出现所有的 customers
LEFT JOIN orders o
	ON c.customer_id = o.customer_id
-- 再进行一次 cutomers 与 shippers 的左 JOIN，要求出现所有的 customers
LEFT JOIN shippers sh
	ON o.shipper_id = sh.shipper_id
ORDER BY c.customer_id
````

---



## USING 语句

`USING ` 语句是一个语法糖，有些情况下，`JOIN` 的判断条件是两种表中的同一个属性，比如这里的条件是 customers 表中的 customer_id 属性与 orders 的 customer_id 属性相同；

````mysql
SELECT
	o.order_id,
    c.first_name
FROM orders o
JOIN customers c
	ON o.customer_id = c.customer_id;
````

可以使用 `USING ` 语句化简：

````mysql
SELECT
	o.order_id,
    c.first_name
FROM orders o
JOIN customers c
	ON USING(customer_id = c.customer_id);
````

多表连接也可以使用 `USING`：

````mysql
SELECT
	o.order_id,
    c.first_name,
    sh.name AS shipper
FROM orders o
JOIN customers c
	USING(customer_id)
LEFT JOIN shippers sh
	USING(shipper_id);
````

多条件连接也可以使用 `USING`，在括号里写入多个属性即可：

````mysql
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	USING(order_id, product_id);
````

---



## NATURAL JOIN 语句

`NATURAL JOIN` 也就是自然连接，这种连接方式下，我们不需要指定连接条件，只要给出表格，MySQL 会根据内置的算法把我们连接，但是这样的连接时不可控制的，所以不建议使用；

语法很简单，如下：

````mysql
SELECT 
	o.order_id,
    c.first_name
FROM orders o
-- 使用 NATURAL JOIN
NATURAL JOIN customers c;
````

---



## CROSS JOIN

`CROSS JOIN`，即交叉连接，作用是连接第一个表的所有记录和第二个表的所有记录，使用时也不需要给出条件，MySQL 会自动完成连接；

比如，a 表有 n 个记录，b 表有 m 个记录，
交叉连接会把依次把 a 表出的 n 个记录取出，分别把 b 表中的 m 个记录加入到其中的每一个记录中。
最后得到了 m * n 个记录；

交叉连接在比如一张表保存颜色，一张保存形状，我们需要获得所有可能的颜色与形状组合时会用到；

语法简答，如下：

````mysql
SELECT 
	c.first_name AS customer,
    p.name AS product
FROM customers c
-- 使用 CROSS JOIN 
CROSS JOIN products p
ORDER BY c.first_name;
````

当然还有一种写法，直接在 FROM 后写两张表格即可，不适应 `JOIN`；

````mysql
SELECT 
	c.first_name AS customer,
    p.name AS product
FROM customers c, orders o
ORDER BY c.first_name
````

---



## UNION 语句

`UNION` 语句可以实现若干次 `SELECT` 结果的组合，即可以把多次的 `SELECT` 结果合成为一张表；

其语法就是在若干个完整 `SELECT` 语句的 `;` 去掉，在两个 `SELECT` 直接加上 `UNION` 即可：

````mysql
-- 第一次
SELECT 属性1, 属性2, 属性3...
FROM 表1
(其他操作)

UNION 

-- 第二次
SELECT 属性1, 属性2, 属性3...
FROM 表2
(其他操作)

UNION 

-- 第三次
SELECT 属性1, 属性2, 属性3...
FROM 表3
(其他操作)

...
````

这里说的联合跟 `JOIN` 的连接不一样，`JOIN` 是连成同一行，拓展了表的行，`UNION` 是列的增加，拓展表的行；

---

### 单表联合

`UNION` 的一个重要功能就是可以对查询结果打标签，比如：

我们有一张 orders 表格，上面有交易的日期属性，我们希望把2019年以后的 order 记作 Active 状态，之前的为 Archived 状态；

可以先使用 `WHERE` 筛选出2019年之后的订单，给这里订单增加一列为 Active，再筛选出 2019 年之前的订单，增加一列为 Archived ：

````mysql
SELECT 
	order_id,
    order_date,
    -- 增加一 status 属性，所有的都为 Active 
    'Active' AS status
FROM orders
WHERE order_date >= '2019-01-01'

UNION

SELECT 
	order_id,
    order_date,
    -- 增加一 status 属性，所有的都为 Archived 
    'Archived' AS status
FROM orders
WHERE order_date < '2019-01-01';
````

- 整个是一个语句，所以第一次查询的 `;` 要去掉；
- 只要列数量相等的表才能联合；
- 联合后的表的属性名称与第一个 `SELECT` 的结果一致；

---

### 两表联合

把两张表得到的 `SELECT` 结果联合；

```mysql
SELECT 
	first_name,
    "c" AS tag
FROM customers
UNION
SELECT 
	name,
	-- 这里不给属性名称也没事，最后的结果是跟第一个一样
    "s" 
FROM shippers;
```

其实 `UNION` 语句没有做什么，就是把两个完整的表格联合起来，行增加，也不需要知道数据是不是来自一张表；

就是要注意表的列数一致；

---

### 多次联合

可以依次把很多表联合起来：

````mysql
SELECT
	customer_id,
    first_name, 
    points,
    "Bronze" AS type
FROM customers 
WHERE points < 2000

UNION 

SELECT
	customer_id,
    first_name, 
    points,
    "Solver" AS type
FROM customers 
WHERE points >= 2000 AND points < 3000

UNION 

SELECT
	customer_id,
    first_name, 
    points,
    "Gold" AS type
FROM customers 
WHERE points >= 3000

ORDER BY first_name;
````

这样注意一下最后的 `ORDER BY` 语句，因为最后联合的结果也是一张表，所以我们可以对联合得到的这张表继续操作，比如之前的学的 `WHERE`、`LIMIT` 等；

整个流程 MySQL 的执行流程还是很符合人的思维的；

这里把所有联合得到的表再按照 `first_name` 排序；

关键是理解联合语句的作用，就是连接表格而已，每个表格内部还可以继续作很多事情，筛选，排序，限制数量什么的，只要最后得到若干张列数量相同的表格就好；