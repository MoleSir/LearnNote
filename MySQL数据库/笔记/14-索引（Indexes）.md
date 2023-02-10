# 索引

索引本质上是数据库引擎用来快速查找数据的数据结构；

例如使用电话簿可以快速找到某人的电话，因为电话簿是按照姓名排序的；

在没有索引的情况下，查询表格需要 MySQL 依次遍历所有行，对数据量很大的情况下，十分耗时；

可以使用索引创建一张表，有两列，一列是某个属性，另一列是对源数据的引用，并且这个表格是按照特定属性排序的；通常，索引的底层通常是树，查询很快；

但索引也有缺点：

- 增加数据库大小；
- 修改表格数据时，也需要更改索引，影响性能；



## 创建索引

基本语法：

````mysql
USE 数据库名称;
CREATE INDEX 索引名称 ON 表格名称 (列);
````

例如：

````mysql
USE sql_store;
CREATE INDEX idx_state ON customers (state);
````

对 sql_store 数据库中的 customers 表格的 state 列创建索引；

使用 `EXPLAIN` 来解释查询：

在创建索引之前，执行命令：

````
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA';
````

得到的查询过程：

- `type = ALL`，说明此次查询会遍历所有行；
- `rows = 1010`，说明要查 1010 行；

而创建索引之后再次执行：

- `type = ref`；
- `rows = 112`；

显然查询的行数少了很多，提高了效率



## 查看索引

基本语法：

````mysql
USE 数据库名称;
SHOW INDEXES IN 数据表格;
````

会显示当前数据表中存在的索引以及索引的属性；

其中有一条是默认的主键索引，只要有主键的表格都会有这样这个索引；

主键索引作为一级索引使用，而我们创建的索引是二级索引，主键会加入到二级索引中，作为对数据条目的引用；



## 前缀索引

索引的列如果是字符串等需要多花费很多空间；所以索引字符串时，不需要加入所有字符，只包含前几个字符或列前缀，这样使得索引比较小，节约空间；

创建前缀索引基本语法：

````mysql
CREATE INDEX 索引名称 ON 表格名称 (列(前缀数量));
````

例如：

````mysql
CREATE INDEX idx_lastname ON customers (last_name(20));
````

在 customers 表中以 last_name 的前 20 个字符作为前缀索引；

具体前缀的数量要根据具体情况而定；

- 数量不能过大，导致内存浪费；
- 数量不能过小，使得有过多的前缀重复（最好的索引就是各不相同，这样查询最快）；

可以使用 `COUNT` 测试不重复的项个数：

````mysql
SELECT 
	COUNT(DISTINCT LEFT(last_name, 1)),
    COUNT(DISTINCT LEFT(last_name, 5)),
    COUNT(DISTINCT LEFT(last_name, 10))
FROM customers;
````

这个查询检查了使用 last_name 的 1，5，10 前缀可以得到的不重复项数量；

- 1 前缀：得到 25，数量太少很多重复，查询效率低；
- 5 前缀：得到 966 很不错，一共就 1010 个条目 ；
- 10 前缀：还是得到 966，那么就很没有必要用 10 个前缀，5 个就好；



## 全文索引

对搜索引擎来说，输入一些关键字，查询的结果并不一定都满足输入关键字的顺序，可能这些关键字在原文中是分开的，甚至顺序是反的；

如何实现，如果这样写：

````mysql
USE sql_blog;
SELECT *
FROM posts
WHERE title LIKE '%react redux%' OR 
	  body LIKE '%react redux%';
````

只能得到标题或正文中确实包含 "react redux" 的表项；这不符合搜索引擎的要求；

要做到这一点需要使用全文索引，基本语法：

````mysql
CREATE FULLTEXT INDEX 索引名称 ON 表格 (列1, 列2, ...);
````

对上面的例子：

````mysql
CREATE FULLTEXT INDEX idx_title_body ON posts (title, body);
````

使用 `MATCH` 与 `AGAINST` 函数组合的方法：

````mysql
SELECT *
FROM posts
WHERE MATCH(title, body) AGAINST('react redux');
````

可以得到标题或正文中包含 'react' 或者 'redux' 的表项；

并且 `AGAINST` 还有其他功能：

 加某个单词前加上 - 号的表示不能出现这个单词，+ 表示必须出现，比如：

````mysql
SELECT *
FROM posts
WHERE MATCH(title, body) AGAINST('react -redux +form' IN BOOLEAN MODE);
````

表示：必须不存在 "redux"，必须存在 "form"；



## 复合索引

使用多列创建一个索引，就是复合索引，复合索引会记录这些列的数据以及指向原表项的引用；

创建复合索引的基本语法：

```mysql
CREATE INDEX 索引名 ON 表格 (列1, 列2, ...);
```

其中列的排列顺序很重要：

MySQL 会在索引表中先对列 1 进行排序，在相同的列 1 中，再对列 2 排序，依次类推；

有了复合索引，当查询语句出现多个列的筛选时，也可以更加高效；

如果此时 customer 表只有 state 的索引，执行：

````mysql
SHOW INDEXES IN customers;
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA' AND points > 1000;
````

效率还是比较低，因为 MySQL 会根据 state 索引先找到 'CA' 顾客，再在这样顾客中依次判断 points；

使用复合索引就可以解决这个问题，因为对相同列 1 的表项，会对列 2 再次排序；

````mysql
CREATE INDEX idx_state_points ON customers (state, points);
````

执行上述创建之后，再次执行查询，会有两个索引可以使用 `idx_state_points` 与 `idx_state`，MySQL 选中效率更高的 `idx_state_points`；0

### 复合索引的排序问题

复合索引的排序十分影响查询效率，通常有这些原则：

- 更频繁使用的列排在前面；
- 基数更高的列排在最前面（基数表示索引中唯一值的数量）；
- 顾及具体查询；

对一个查询，可能存在多个索引可以使用，MySQL 会选中最佳的使用，但也可以指向强制其使用：

````mysql
USE sql_store;
EXPLAIN SELECT customer_id
FROM customers
-- 必须使用 idx_lastname_state
USE INDEX (idx_lastname_state)
WHERE state = 'NY' AND last_name LIKE 'A%';
````



## 索引忽略

### 使用索引但效率低

某些情况下，使用了索引但效率还是低；

例如现在 customers 表有 (state, points) 索引，执行：

````mysql
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA' OR points > 1000;
````

得到的查询过程，仍需要检查 1010 行；这是因为对  (state, points) 索引来说，points 的排序只在相同的 state 表项进行；

而查询语句是 `OR`，也就是说 `points > 1000` 判断需要对所有都判断；

改进的方法是增加一个单独对 `points` 的所有，并且把查询拆分，使用 `UNION` 合并：

````mysql
EXPLAIN 
	SELECT customer_id
    FROM customers
    WHERE state = 'CA'
    UNION
    SELECT customer_id
    FROM customers
    WHERE points > 1000;
````

### 索引无效

当 `WHERE` 出现表达式，使得索引失效：

````mysql
EXPLAIN SELECT customer_id
FROM customers
-- 由于这个表达式，MySQL 无法以最优方式利用索引
WHERE points + 10 > 2010;
````

所以，想让 MySQL 优化查询，必须把列单独提出；



## 索引排序

索引的本质是将某列排序；那么如果我们希望对某列排序，并且已经存在了次列的索引；那 MySQL 就可以直接使用索引中的顺序，不需要再排序一次；

### 有索引的列排序

````mysql
USE sql_store;
SHOW INDEXES IN customers;
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state;
````

得到的查询结果中：

- `type = idx_state_points`，使用索引排序
- `Extra = Using index`，使用索引；

### 没有索引的列排序

如果对没有索引的列排序：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY first_name;
````

- `Extra = Using filesort` 很耗时
- `type = ALL`；

> PS：使用如下语句可以查看 MySQL 服务器上一次执行语句的花费
>
> ````mysql
> SHOW STATUS LIKE 'last_query_cost';
> ````

### 复合索引列排序

在 `ORDER BY` 语句中，可以写多个列，意味着先对第一个列排序，如果相同再按第二个列，以此类推；

这个规律与创建复合索引时完全一致；

如果表格中存在了 `(state, points)` 的索引，

````mysql
CREATE INDEX idx_state_points ON customers;
````

对这两个列的排序有这些情况：

#### state, points

排序的顺序与复合索引顺序相同的话，也可以有很高的效率：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state, points;
````

#### points, state

排序的顺序与复合索引顺序相反的话，效率低：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state, points;
````

因为复合索引中是先对 state 排序，相同 state 的才对 points 排序；而查询中是对所有的 points 排序；不能从索引中获取信息；

#### state

单独对 state 排序，是直接从索引中得到信息的：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state;
````

#### points

单独对 state 排序，是不可以直接从索引中得到信息的：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state;
````

但根据索引的定义，如果加上 `WHERE` 也可以使用索引：

````mysql
EXPLAIN SELECT customer_id
FROM customers
WHERE state = 'CA'
ORDER BY points;
````

#### state, points DESC

排序的顺序与复合索引顺序相同，但顺序不同，不从索引中得到排序信息：

````mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state, points DESC;
````

#### state DESC, points DESC

排序的顺序与复合索引顺序相同，但顺序都反，可以从索引中得到排序信息：

```mysql
EXPLAIN SELECT customer_id
FROM customers
ORDER BY state DESC, points DESC;
```

...

综上，只要理解索引的工作原理，就可以很快分析处结果了；



## 覆盖索引

覆盖索引指的是一个包含所有满足查询需要的数据的索引，MySQL 可以不看原数据就得到结果，比如下面这个：

````mysql
-- 只选中 customer_id 主键
EXPLAIN SELECT customer_id 
FROM customers
ORDER BY state;
````

state 的索引中保存了 state 与 主键信息，那么这个查询不需要经过原始数据就可以通过索引表完成，这就是覆盖索引；

但如果超过了索引表的范围，就需要去原表格中获取数据：

````mysql
-- 选所有
EXPLAIN SELECT * 
FROM customers
ORDER BY state;
````



## 维护索引

索引需要内存空间，应该避免创建重复的索引；

- MySQL 允许创建对相同列的索引，只要名称不同即可；那么两个索引表有完全相同的数据，并且更新表格还需要多更新一个索引，浪费空间、浪费性能，需要避免；创建索引之前先看，是不是已经存在；

- 如果已经存在复合索引 (A, B)，再创建 (A) 就是浪费，(A, B) 本来就是先对 A 排序；

    但有了 (A, B)，再创建 (B) 就不算浪费;

记住在创建索引前，先检查这个索引是不是已经存在了！