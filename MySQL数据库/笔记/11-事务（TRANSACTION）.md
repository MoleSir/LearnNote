# 事务

事务是代表单个工作单元的一组 SQL 语句 ；

所有这些语句都必须同时成功执行，否则就都失败；

比如银行，从我的账户取出10元是一个操作，将10元放入我朋友的账户是另一个操作。完成我向朋友转账这个过程，必须上述两个操作都完成；

如果某个失败，另一个即使成功，也需要撤回；



## 事务特点

- **原子性**：一个事务的语句要么全部执行成功，要么就相等于没有执行；
- **一致性**：使用事务，保存数据库的一致性；
- **隔离性**：事务相互隔离，不会互相干扰，对表正在被某个事务操作时，其他事务必须等待
- **持久性**：事务一旦被提交，事务产生的影响是永久的



## 创建事务

创建事务的基本语法：

````mysql
START TRANSACTION;
事务程序（每条之间用 ； 隔开）
COMMIT;
````

举例：

````mysql
USE sql_store;

START TRANSACTION;

INSERT INTO orders (customer_id, order_date, status)
VALUES (1, '2019-01-01', 1);

INSERT INTO order_items
VALUES (LAST_INSERT_ID(), 1, 1, 1);

COMMIT;
````

创建一个事务，必须完成两个操作都成功后，再提交 `COMMIT` 变化；否则恢复到执行事务之前；

除了 `COMMIT` 提交事务产生的变化，还可以使用 `ROLLBACK` 撤回变化；



## 并发锁

若干多个用户访问一个数据库出现并发问题；

当一个用户对一个表的某行进行事务操作，MySQL 给此行上锁；

其他的用户使用事务操作这个表会阻塞，直到第一个用户的事务被 `COMMIT` 完成；或者 `ROLLBACK`  撤回事务；



## 并发存在的问题

并发执行时不上锁会产生的问题：

- **Lost Updates**，当两个事务更新同一行，最后提交的事务覆盖了先前所做的修改；

- **Dirty Reads**，指一个事务读取了尚未被提交的数据；

    比如事务 A 先修改了 points 属性，但在其提交之前，事务 B 读取了 points，之后事务 A 有语句失败；那么 A 对 pointes 的修改被撤回，B 却拿到了修改后的错误的 points

- **Non-repeating Reads**，在事务中读取相同的数据两次得到不同的结果；

    比如：事务 A 先读取 ponits，事务 B 再修改 points，事务 A 最后读取 points，导致事务 A 前后读取的 points 不一样；

- **Phantom Reads**，当查询中缺少了一行或者多行，因为另一个事务正在修改数据；

    比如务 A 对查询表格的过程中，事务 B 插入新的数据，导致事务 A 查询结果不正确

  

## 事务隔离等级

MySQL 提供四种标准事务隔离，也就是上锁的条件；

- READ UNCOMMITED：运行事务读取没有被提交的数据，不设置任何锁，就是导致这些问题的原因；
- READ COMMITED：事务只能读取已经提交的数据，防止了 Dirty Read 
- REPEATBALE READ：在这个级别，MySQL 确保读取到的数据返回相同的结果
- SERIZLIZABLE（可序化）：可以解决所有问题，若干数据在期间改动，事务会待定，以获取最新数据，增加负担，但可靠；

具体的四种隔离的问题与解决问题代码在 Code 文件夹；

### 查看当前事务隔离

````mysql
SHOW VARIABLES LIKE 'transaction_isolation';
````

### 修改事务隔离等级

- 设置下一次事务的隔离等级为 ...

    ````mysql
    SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
    ````

- 设置本次 MySQL 连接所创建的事务隔离等级为 ...

    ````mysql
    SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
    ````

- 设置之后的所有事务等级为..

    ````mysql
    SET GLOBAL TRANSACTION ISOLATION LEVEL SERIALIZABLE;
    ````



## 死锁

两个客户之间互相等待对方提交；

例如：

User1：

````mysql
USE sql_store;
START TRANSACTION;
UPDATE customers SET state = 'VA' WHERE customer_id = 1;
UPDATE orders SET status = 1 WHERE order_id = 1;
COMMIT;
````

User2

````mysql
USE sql_store;
START TRANSACTION;
UPDATE orders SET status = 1 WHERE order_id = 1;
UPDATE customers SET state = 'VA' WHERE customer_id = 1;
COMMIT;
````

用户 2 与用户 1 的更新顺序相反，用户 1 等待用户 2，用户 2 等待用户 1；



