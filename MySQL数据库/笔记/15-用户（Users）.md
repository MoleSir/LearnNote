# 用户

数据保持在 MySQL 的服务器；

如果要操作数据库，就需要创建一个用户并且赋予这个用户一定的权限：

- 比如对应用程序用户，只希望可以读写数据库中的数据，不希望其可以修改数据库，添加表格等；

- 而当数据库需要多人维护，继创建一个管理员一起管理某个数据库，甚至整个 MySQL 服务器；

都是与用户操作相关；



## 创建用户

创建用户基本语法：

````mysql
CREATE USER 用户名(@ip地址\域名) (IDENTIFIED BY '密码')
````

其中 `()` 还是代表可以不写；如果在用户名后加 `@ip地址\域名` 就指定了用户只能从这些主机登录；

下面是几个例子：

- 不指定用户登录主机，可以从任何 ip 连接 MySQL 服务器：

    ````mysql
    CREATE USER john4;
    ````

- 创建用户并且设定密码：

    ````mysql
    CREATE USER john IDENTIFIED BY '123456';
    ````

- 指定用户只能从某个 ip 连接数据库：

    ````mysql
    CREATE USER john1@127.0.0.1;
    ````

- 指定用户只能从服务器所在的主机连接数据库：

    ````mysql
    CREATE USER john2@localhost;
    ````

- 指定用户只能从某个域名下的主机登录：

    ````mysql
    CREATE USER john3@codewithmosh.com;
    ````



## 查看用户

查看 MySQL 服务器下默认创建的 mysql 数据库中的 user 表格查看用户信息：

````mysql
SELECT * FROM mysql.user;
````



## 删除用户

基本语法：

````mysql
DROP USER 用户(@ip地址\域名);
````

PS：如果创建时候指定了登录主机，那么删除时也要加上；



## 修改密码

为别人修改密码：

````mysql
SET PASSWORD FOR 用户名 = '新密码';
````

修改当前用户，哪个用户执行这句代码，就修改谁的密码

````mysql
SET PASSWORD = '新密码';
````



## 赋予权限

基本语法：

````mysql
GRANT 操作1, 操作2, ...
ON 数据表
TO 用户(@ip地址\域名);
````

- `操作1, 操作2, ...`：希望给予用户的操作，就是 `INSER`、`UPDATE`、`SELECT`、`CREATE FUNCTION` 等操作；
- `数据表`：给予用户操作什么数据表的权限：
    - `数据库1.*` ：可以操作数据库1 的所有数据表；
    - `*.*`：可以操作当前 MySQL 服务器所有数据库的数据表；
- `用户(@ip地址\域名)`：赋予哪个用户权限（PS：如果创建时候指定了登录主机，那么也要加上）；

举例：

### 普通用户

仅仅创建用户，允许其连接数据库，读写数据，不能创建表格、修改表格：

````mysql
CREATE USER moon_app@127.0.0.1 IDENTIFIED BY '1234';
GRANT SELECT, INSERT, UPDATE, DELETE, EXECUTE
ON sql_store.*
TO moon_app@127.0.0.1;
````

### 管理员

管理员，可以修改数据库，创建新表格等：

````mysql
GRANT ALL
ON *.*
TO john;
````



## 查看权限

为其他用户查看权限：

```mysql
SHOW GRANTS FOR 用户名;
```

查到当前用户权限：

````mysql
SHOW GRANTS;
````



## 撤销特权

基本语法：

````mysql
REVOKE 操作1, 操作2, ...
ON 数据表
FROM 用户(@ip地址\域名);
````

相对与赋予权限，只要把 `GRANT` 改为 `REVOKE`，`To` 改为 `FROM`；

举例：

给 moon_app 创建视图的权力

````mysql
GRANT CREATE VIEW
ON sql_store.*
TO moon_app;
````

撤销 moon_app 创建视图的能力

````mysql
REVOKE CREATE VIEW
ON sql_store.*
FROM moon_app;
````

