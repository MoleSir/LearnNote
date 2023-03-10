# MySQL

MySQL 是最流行的关系型数据库管理系统，在 WEB 应用方面 MySQL 是最好的 RDBMS(Relational Database Management System：关系数据库管理系统)应用软件之一。



## 数据库

数据库（Database）是按照数据结构来组织、存储和管理数据的仓库。

每个数据库都有一个或多个不同的 API 用于创建，访问，管理，搜索和复制所保存的数据。

可以将数据存储在文件中，但是在文件中读写数据速度相对较慢。

所以，现在使用关系型数据库管理系统（RDBMS）来存储和管理大数据量。所谓的关系型数据库，是建立在关系模型基础上的数据库，借助于集合代数等数学概念和方法来处理数据库中的数据。

**RDBMS** 即关系数据库管理系统(Relational Database Management System)的特点：

- 1.数据以表格的形式出现
- 2.每行为各种记录名称
- 3.每列为记录名称所对应的数据域
- 4.许多的行和列组成一张表单
- 5.若干的表单组成database



## RDBMS 术语

- **数据库:** 数据库是一些关联表的集合。
- **数据表:** 表是数据的矩阵。在一个数据库中的表看起来像一个简单的电子表格。
- **列:** 一列(数据元素) 包含了相同类型的数据，例如邮政编码的数据，类似一个属性；
- **行：**一行（=元组，或记录）是一组相关的数据，例如一条用户订阅的数据。
- **冗余**：存储两倍数据，冗余降低了性能，但提高了数据的安全性。
- **主键**：主键是唯一的。一个数据表中只能包含一个主键。你可以使用主键来查询数据。
- **外键：**外键用于关联两个表。
- **复合键**：复合键（组合键）将多个列作为一个索引键，一般用于复合索引。
- **索引：**使用索引可快速访问数据库表中的特定信息。索引是对数据库表中一列或多列的值进行排序的一种结构。类似于书籍的目录。
- **参照完整性:** 参照的完整性要求关系中不允许引用不存在的实体。与实体完整性是关系模型必须满足的完整性约束条件，目的是保证数据的一致性。

MySQL 为关系型数据库(Relational Database Management System), 这种所谓的"关系型"可以理解为"表格"的概念, 一个关系型数据库由一个或数个表格组成, 如图所示的一个表格:

![img](https://www.runoob.com/wp-content/uploads/2014/03/0921_1.jpg)

- 表头(header): 每一列的名称;
- 列(col): 具有相同数据类型的数据的集合;
- 行(row): 每一行用来描述某条记录的具体信息;
- 值(value): 行的具体信息, 每个值必须与该列的数据类型相同;
- **键(key)**: 键的值在当前列中具有唯一性。



## MySQL

MySQL 是一个关系型数据库管理系统，由瑞典 MySQL AB 公司开发，目前属于 Oracle 公司。MySQL 是一种关联数据库管理系统，关联数据库将数据保存在不同的表中，而不是将所有数据放在一个大仓库内，这样就增加了速度并提高了灵活性。

- MySQL 是开源的，目前隶属于 Oracle 旗下产品。
- MySQL 支持大型的数据库。可以处理拥有上千万条记录的大型数据库。
- MySQL 使用标准的 SQL 数据语言形式。
- MySQL 可以运行于多个系统上，并且支持多种语言。这些编程语言包括 C、C++、Python、Java、Perl、PHP、Eiffel、Ruby 和 Tcl 等。
- MySQL 对 PHP 有很好的支持，PHP 是很适合用于 Web 程序开发。
- MySQL 支持大型数据库，支持 5000 万条记录的数据仓库，32 位系统表文件最大可支持 4GB，64 位系统支持最大的表文件为8TB。
- MySQL 是可以定制的，采用了 GPL 协议，可以修改源码来开发自己的 MySQL 系统；

MySQL 不是一个数据库，而是一款关系型数据库管理系统，用户通过 MySQL 管理数据库；



## SQL 语言

**SQL** (Structured Query Language:结构化查询语言) 是用于管理关系数据库管理系统（RDBMS）。 SQL 的范围包括数据插入、查询、更新和删除，数据库模式创建和修改，以及数据访问控制。

MySQL 是一个软件，我们可以使用 SQL 语言来控制 MySQL 实现各种对数据的操作；

- SQL 指结构化查询语言，全称是 Structured Query Language。
- SQL 可以访问和处理数据库，包括数据插入、查询、更新和删除。
- SQL 在1986年成为 ANSI（American National Standards Institute 美国国家标准化组织）的一项标准，在 1987 年成为国际标准化组织（ISO）标准。



## 总结

数据保存在数据库中，即总是需要保存在一台主机内；

MySQL 是一个关系型数据库管理系统，使用 SQL 语言对数据库进行管理；

MySQL 是一个客户端-服务器模式，数据保存在 MySQL 服务器主机上；其他主机想要获取数据，就需要以客户端的身份连接到 MySQL 服务器；通过一系列的 SQL 语句对 MySQL 服务器进行操作；

在学习 MySQL 的过程前，会先下载 MySQL，其中就包括了 MySQl 服务器与客户端的应用程序；运行 MySQL 服务器程序后，我们的主机也就成为了一台 MySQL 服务器，数据被保存在我们主机内。而其他客户端，也可以是我们主机的一个 MySQL 客户端可以请求对 MySQL 服务器的连接，执行操作；

学习的过程中就是使用本机的一个 MySQL 客户端对本机的 MySQL 服务器进行操作；