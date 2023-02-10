# MySQL DataBase
此仓库用于存放学习 MySQL 的代码与笔记，[学习教程](https://www.bilibili.com/video/BV1UE41147KC/?spm_id_from=333.999.0.0&vd_source=ef8fad1674cc752396ea9a1157e43f29)；

以下为 MySQL 最基本的操作：



## 增

### 创建数据库

````mysql
CREATE DATABSE 数据库名;
````

### 创建表格

````mysql
CREATE TABLE 表格名(
	列名1 列1数据类型 列1属性,
    列名2 列2数据类型 列2属性,
    列名3 列3数据类型 列3属性,
   	...
    列名n 列n数据类型 列n属性
);
````

常见属性：

- `NOT NULL`：非空；
- `AUTO_INCREMENT`：自动递增；
- `PRIMARY KEY`：主键；

### 插入记录

````mysql
INSERT INTO 数据库名.表格名(列名1, 列名2, 列名3, ..., 列名n)
VALUES (数值1, 数值2, 数值3, ..., 数值n)
````

### 增加列

```mysql
ALTER TABLE 数据库名.表格名
	ADD 列名1 列1数据类型 列1属性,
	...
	ADD 列名n 列n数据类型 列n属性;
```



## 删

### 删除数据库

````mysql
DROP DATABASE 数据库名;
````

### 删除表格

````mysql
DROP TABLE 数据库名.表格名;
````

### 删除记录

````mysql
DELETE FROM 数据库名.表格名
WHERE 条件;
````

- 使用 `DELETE FROM` 指定删除的表格；
- 使用 `WHERE` 确定删除哪一或哪些列；

### 删除列

````mysql
ALTER TABLE 数据库.数据表
	DROP 列名1,
	...
	DROP 列名n;
````



## 改

### 修改记录

````mysql
UPDATE 数据库名.表格名
SET 值
WHERE 条件;
````

- 使用 `UPDATE` 指定修改的表格；
- 使用 `SET` 来设置具体的更新内容；
- 使用 `WHERE` 来选中更新的是哪一或者哪些行；

### 修改列

````mysql
ALTER TABLE 数据库名.表格名
	MODIFY 列名1 列1数据类型 列1属性,
	...
	MODIFY 列名n 列n数据类型 列n属性;
````



## 查

### 查看表格

````mysql
SELECT (DISTINCT)列1, 列2, 列3, ..., 列n
FROM　数据库名.表格
WHERE 条件 
ORDER BY 列名 (DESC);
````

- 使用 `SELECT` 选择要查看的列，`*` 代表所有列；
- 使用 `FROM` 选择要查看的数据表；
- 使用 `WHERE` 筛选出要查看的记录；
- 使用 `ORDER BY` 对查询经过排序；

### 连接表格

````mysql
SELECT 列1, 列2, 列3, ..., 列n
FROM 数据库名1.表格1
JOIN 数据库名2.表格2
	ON 条件;
````

- 使用 `SELECT` 选择要查看的列；
- 使用 `FROM` 选择一个需要合并的数据表；
- 使用 `JOIN` 选择另一个需要合并的数据表；
- 使用 `ON` 给出合并的条件；

### 合并表格

````mysql
表1
UNION
表2;
````

表1，表2 一般是由 `SELECT` 语句得到；
