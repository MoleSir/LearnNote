# 选择语句 The SELECT Statement 

学习如何在单一表格中检索数据；

---



## USE 语句

`USE` 命令用来设置当前工作的数据库，这样才能对其中的表格进行操作，语法为：

````mysql
USE 数据库名称;
````

例如，打开 `sql_store` 数据库：

````mysql
USE sql_store;
````

---



## SELECT 语句

`SELECT ` 用于查找表格中的表项目，其有很多附加语句，语法如下：

````mysql
SELECT 属性1, 属性2 ...
FROM 需要查找的数据表
WHERE 过滤条件
ORDER BY 排列属性
LIMIT 需要查找的表项数量
````

- `SELECT` 后加上希望查找的是哪些列（也就是属性），用 `,` 隔开，如果要获取所有列，使用 `SELECT *`；
- `FROM` 后加上希望查找的是那张表格；
- `WHERE` 后加上条件，MySQL 会将这个条件去匹配表中的每一项，匹配成功的表项才会被查找出（非必要）；
- `ORDER BY` 后加属性，MySQL 会把之前查找到的所有表现按这些属性排序（非必要）；
- `LIMIT` 后加上需要查找的项目数，MySQL 会把排好序的表项的前这么多个显示给我们（非必要）；

这五个命令中 `WHERE` 、`ORDER BY` 与 `LIMIT` 是非必要的，可以不写，但是，需要注意，这五个命令的顺序不能改变，必须按照上述顺序写，否则报错；

---

### 显示表格中的所有数据

我们先使用最简单的 `SELECT` 语句，将 `customers` 表中所有的数据都显示，感受其用法：

````mysql
USE sql_store;

SELECT *
FROM customers;
````

---

### 显示指定的属性

现在我们只想看到顾客的 `name`，与 `points` 属性：

````mysql
USE sql_store;

SELECT name, points
FROM customers;
````

在 `SELECT` 后指定显示的属性，MySQL 在显示时会按照顺序给出各个属性，比如这里就是先 name，后 points；

---

### 增加新的属性

`SELECT` 除了可以选择原有的属性以外，还可以增加新的属性，这些属性需要由旧属性推导得到，比如我们显示 points + 10 属性：

````mysql
SELECT name, points + 10
FROM customers;
````

MySQL 会把每个顾客的 points 属性加 10 后显示，当然也支持更复杂的表达式：

````mysql
SELECT name, unit_price * number;
FROM products;
````

这里就把每个商品的 单价 unit_price 与 出售数量 number 相乘后显示；

但是如果我们直接这样写，这个属性是没有名称的，默认就是我们给出表达式 `unit_price * number` 会比较难看，MySQL 允许我们给新属性命名，语法就是在表达式后 + `AS 新属性名称`： 

````mysql
SELECT name, unit_price * number AS total_price
FROM products;
````

现在显示的表格中就会出现新的属性 `total_price`；

如果我们希望名称中有空格就用单引号或者双引号命名：

````mysql
SELECT name, unit_price * number AS 'total price'
FROM products;
````

---

下面来是其他三个指令的用法：

---



## WHERE 语句

查找表项时，通常都不是想全部显示，我们希望 MySQL 帮助我们把我们想要的筛选出来，这就需要`WHERE` 语句，可以在其后加上对属性的一些条件语句，比如我们希望筛选出 `points` 属性大于 3000 顾客：

````mysql
SELECT *
FROM customers
WHERE points > 3000; 
````

 `points > 3000 ` 就是一个条件，MySQL 会让每一个表项都去执行这个条件判断，只有符合要求才能显示，达到了筛选的效果；

除了 `>` ，`WHERE` 还支持：

- `<, <=, >=, =, <>` 等比较运算符；
- `AND, OR, NOT` 逻辑运算符；
- `LIKE, REGEXP` 字符串匹配表达式；

下面一个一个看，

PS：说明一下，为了方便，下面的例子省略：

````mysql
USE sql_store;
SELECT *
FROM customers
````

只关注 `WHERE` 语句；

---

### 比较运算符

其中大于小大等都比较常规，这里就说一些等于和不等于；

MySQL 中的等号运算符是 `=` ，不等运算符是 `<>` 比较特殊，跟大多语言都不一样；下面看几个例子：

#### state 为 VA 的顾客

这是一个字符串的类型，使用单引号或者双引号，不区分大小写，写 'va' 也是一样的，MySQL 不区分大小写

```mysql
WHERE state = 'VA';
```

#### state 不为 VA 

````mysql
WHERE state <> 'VA';
````

#### birth_date 大于 1990-01-01 

MySQL 中有日期的标志表达形式： '年-月-日'，可以直接使用比较运算法比较

````mysql
WHERE birth_date > '1990-01-01';
````

----

### 逻辑运算符

使用逻辑运算符 `AND, OR, NOT` 可以实现多个条件的筛选，既在 `WHERE` 后写上多个筛选语句并且用逻辑运算符组合起来，与其他语言的 `if` 判断类型；

OR AND 一起使用时，先计算 AND，再计算 OR，可以用 () 来明确指定运算顺序；

#### birth_date 大于 1990-01-01 且 points 大于 1000 

````mysql
WHERE brith_date > '1990-01-01' AND points > 1000;
````

#### birth_date 大于 1990-01-01 或 points 大于 1000

`````mysql
WHERE birth_date > '1990-01-01' OR points > 1000;
`````

#### birth_date 大于 1990-01-01 或（points 大于 1000 的 并 state 为 VA ）

````mysql
WHERE birth_date > '1990-01-01' OR ( points > 1000 AND state = 'VA' );
````

#### 除了 birth_date 大于 1990-01-01 或者 points 大于 1000 

NOT 即为取反

````mysql
WHERE NOT ( birth_date > '1990-01-01' OR points > 1000 );
````

---

### 字符串匹配

#### LIKE 语句

在 `WHERE` 后使用 `LIKE` 可以完成字符串的匹配筛选，语法为：

````mysql
WHERE 属性 LIKE '匹配字符串'
````

多说无益，直接看例子就好：

- **属性 last_name 以 b 开头的表项**

    `%` 代表任意字符，表示开头是 `b`，之后任意；

    ````mysql
    WHERE last_name LIKE 'b%';
    ````

- **属性 last_name 以 brush 开头的表项**

    除了可以匹配一个字符，还可以多个：

    ````mysql
    WHERE last_name LIKE 'brush%';

- **属性 last_name 中包含 b 的表项**

    % 可以放置在任意位置，表示指定的字母相对位置可以为任意字符

    ````mysql
    WHERE last_name LIKE '%b%';

- **属性 last_name 以 y 结尾的表项**

    ````mysql
    WHERE last_name LIKE '%y';
    ````

- **属性 last_name 以 y 结尾的并且长度为2个字符的表项**

    % 代表任意个数的字符， '_' 代表一个字符

    ````mysql
    WHERE last_name LIKE '_y';

- **属性 last_name 以 y 结尾的并且长度为6个字符的表项**

    ````mysql
    WHERE last_name LIKE '____y';

- **属性 last_name 以 y 结尾、以 b 开头并且长度为6个字符的表项**

    ````mysql
    WHERE last_name LIKE 'b___y';

- **选择手机号不以 9 结尾的表项**

    也可以配合 `NOT` 使用

    ````mysql
    WHERE phone NOT LIKE '%9';

---

#### REGEXP 语句

除了 `LIKE` 语句可以完成字符串匹配，还有功能更强大的正则表达式 `REGEXP` ，其语法跟 `LIKE` 是一致的，下面就直接看例子；

- **属性 last_name 中包含 field 的表项**

    `REGEXP` 语句不需要加 % 即可表示匹配任意字符

    ````mysql
    WHERE last_name REGEXP 'field';
    ````

- **属性 last_name 中以 field 开头的表项**

    `'^'` 表示以什么开头

    ````mysql
    WHERE last_name REGEXP '^field';
    ````

- **属性 last_name 中以 field 结尾的表项**

    `'$'` 表示以什么结尾，`$` 放置在字符串后

    ````mysql
    WHERE last_name REGEXP 'field$';
    ````

- **属性 last_name 中包含 field 或者 mac 的表项目**

    使用 `|` 可以有类型 `OR` 的效果，在其所有两个各写一个表达式，只要一个匹配成功即可；因为这是字符串匹配，一定不要乱加空格；

    ````mysql
    WHERE last_name REGEXP 'field|max';
    ````

- **属性 last_name 中包含 field 或者 mac 或者 rose 的表项**

    当然可以使用多个 `|`

    ````mysql
    WHERE last_name REGEXP 'field|mac|rose';
    ````

- **属性 last_name 中 以 field开头 或 包含 mac 或 包含 rose 的表项**

    `|` 配合 `^` `$` 使用：

    ````mysql
    WHERE last_name REGEXP '^field|mac|rose';
    ````

- **属性 last_name 中包含 ge 或者 ie 或者 me 的表项**

    当然可以用两个 `|` 实现，但是正则表达式提供了一种语法实现，使用 `[]` ，看实现：

    ````mysql
    WHERE last_name REGEXP '[gim]e';
    ````

    在字母 e 前加 `[gim]` 表示可以匹配 `e` 前有 `g`、`i` 或 `m`；

- **属性 last_name 中包含 mf 或者 ie 或者 el 的表项**

    `[]` 放在后面也是同理：

    ````mysql
    WHERE last_name REGEXP 'e[fm1]';
    ````

- **属性 last_name 中包含 e之前为 a 到 h 的任意一个字符的表项**

    如果匹配的项很多时，要在 `[]` 写很多，可以使用 `[a-f]` 这样的语法，表示从 `a` 到 `f`：

    ````mysql
    WHERE last_name REGEXP '[a-h]e';
    ````

---

### IN 语句

`IN` 语句是一个语法糖，当我们对某个属性需要进行多次或判断时，需要些很多多余的句子，比如筛选出 state 为 Va 或者 FL 或者 GA 的，会这样写：

````mysql
WHERE state = 'VA' OR state = 'FL' OR state = 'GA';
````

MySQL 提供了 `IN` 语句简化：

````mysql
WHERE state IN ('VA', 'FL', 'GA');
````

把各个选项都放入 `()` 中即可；

----

### BETWEEN 语句

`BETWEEN` 也是一个语法糖，用于简化输入返回时的 `WHERE`语句，比如筛选 points 在 1000 与 3000 之间的：

````mysql
WHERE points >= 1000 AND points <= 3000
````

MySQL 提供 `BETWeen` 简化

````mysql
WHERE points BETWEEN 1000 AND 3000;
````

在 `BETWEEN AND` 后写入上下限；

---



## ORDER BY 语句

`ORDER BY` 语句允许我们对筛选到的表项进行排序，语法很简单：

````mysql
SELECT *
FROM customers
ORDER BY 属性1, 属性2, 属性3...
````

将希望用来排序的属性放在 `ORDER BY` 后，MySQL 会先对第一个属性排序，如果有若干项的属性1相同，再对这几项的属性2排序，依次类推；

默认排序是升序，即a,b,c,,,,，1,2,3,4,,,，如果想要降序排序，就在希望降序排序的属性后加 `DESC`，注意是希望哪个倒叙就加在哪个后面；

 在 MySQL 中，即使没有被 SELECT 的属性也可以作为排序依据，在其他的数据库中可能不行；

下面是几个例子（同前，只显示 `ORDER BY` 的代码）：

### 以 first_name 升序排序

````mysql
ORDER BY first_name;
````

### 按 state 升序，first_name 降序排序

````mysql
ORDER BY state, first_name DESC;
````

---



## LIMIT 语句

`LIMIT` 可以选择需要筛选的数量，在表格结果筛选与排序后（如果有筛选与排序的话），取出先若干个显示；

语法很简单，在 `LIMIT` 后加数量即可，如果数量大于总表项，那么也只能显示那么多，这个语句就没有作用了

````mysql
SELECT *
FROM sql_store.customers
# 只显示三项
LIMIT 3;
````

除了设置显示个数的功能，`LIMIT` 还能写入两个数字参数：

````
LIMIT a, b;
````

a, b 都是数字，表示跳过前 a 项，显示之后的 b 项；

看下面的例子：

````mysql
SELECT *
FROM sql_store.customers
# 6 表示偏移量，跳过前 6 个记录，返回 7, 8, 9 这 3 个
LIMIT 6, 3;
````

