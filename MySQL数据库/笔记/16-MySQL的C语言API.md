# MySQL 的 C 语言 API

MySQL 数据库是 C/S 结构，即：客户端和服务器端；

如果部署好了 MySQL 服务器，想要在客户端访问服务器端的数据，在编写程序的时候就可以通过官方提供的 C 语言的 API 来实现；

在程序中连接 MySql 服务器，主要分为已经几个步骤：

1. 初始化连接环境；
2. 连接 mysql 的服务器，需要提供如下连接数据：
    - MySQL 服务器的 IP 地址；
    - MySQL 服务器监听的端口（默认端口是 3306）；
    - 连接服务器使用的用户名（默认是 root），和这个用户对应的密码；
    - 要操作的数据库名；
3. 连接已经建立，后续操作就是对数据库数据的增删改查；
    - 这些操作都是需要通过 sql 语句完成；
    - 数据查询：通过调用 api 执行一个查询的 sql 语句；
    - 数据修改：通过调用 api 执行一个查询的 sql 语句；
4. 如果要进行数据的添加/删除/更新，需要进行事物的处理
    - 需要对执行的经过进行判断；
        - 成功：提交事务；
        - 失败：数据回滚；
5. 数据库的读操作 -> 查询 -> 得到结果集；
6. 遍历结果集 -> 得到了数据；
7. 释放资源；



## 初始化连接环境

最开始需要初始化连接环境，使用 MySQL 提供的 API 完成：

````c
MYSQL* mysql_init(MYSQL *mysql);
````

- 参数 `mysql` 写 `null` 即可；
- 返回值：该函数将分配、初始化、并返回新对象，通过返回的这个对象去连接 MySQL 服务器；



## 连接 mysql 服务器

````c
MYSQL* mysql_real_connect(
	MYSQL *mysql,
	const char *host,
    const char *user,
    const char *passwd,
    const char *db,
    unsigned int port,
    const char *unix_socket,
    unsigned long clinet_flag
);
````

- 参数：
    - `mysql`：`mysql_init()` 函数的返回值；
    - `host`：mysql 服务器的主机地址，写 IP 地址即可；
        - `null` 与 `'loaclhost'` 代表本地连接；
    - `user`：连接 mysql 服务器的用户名，默认为 `root`；
    - `passwd`：连接 mysql 服务器用户对应的密码；
    - `db`：要使用的数据库名；
    - `port`：连接 mysql 服务器监听的端口；
        - 如果 == 0，使用 mysql 的默认端口为 3306；
        - 不等于 0，使用指定的这个端口；
    - `unix_socket`：本地套接字，不使用指定为 `NULL`；
    - `client_flag`：通常为 0；
- 返回值：
    - 连接成功返回 MySQL* 连接实体，也就是第一个参数；
    - 连接失败返回 `NULL`；



## 执行 sql 语句

执行 sql 语句都是使用一个函数，在参数中将 sql 语句由字符串形式输入：

````c
int mysql_query(MYSQL* mysql, const char *query);
````

- 参数：
    - `mysql`：操作的连接实体，`mysql_real_connect` 的返回值；
    - `query`：一个可以执行的sql语句, 结尾的位置不需要加 `;`；
- 返回值：
    - 如果查询成功，返回0。如果是查询, 结果集在 mysql 对象中；
    - 如果出现错误，返回非0值；



## 获取结果集

如果 `mysql_query` 执行的是一个 `SELECT` 语句，那么查询结果会被保存在 mysql 对象中：

````c
MYSQL_RES* mysql_store_result(MYSQL* mysql);
````

- 参数：
    - `mysql`：操作 MySQL 服务器的实体；
- 返回值：
    - 查询成功返回 `MYSQL_RES*`，执行一块内存，保存结果；
    - 查询失败返回 `NULL`；



## 得到结果集的列数

查询结果是一张表，遍历表格时，需要知道表格有几列：

```c
unsigned int mysql_num_fields(MYSQL_RES* result);
```

- 参数：

    - `result`：通过 `mysql_store_result` 得到的 `MYSQL_RES` 地址；

- 返回值：

    - 查询得到的列数；

    

## 获取表头 -> 列名 (字段名)

表格中存在数据，查数据时，需要知道对应数据属于什么字段（既属于哪列）；这就需要知道列名（也叫字段名）；

````c
MYSQL_FIELD* mysql_fetch_fields(MYSQL_RES* result);
````

- 参数：
    - `result`：通过 `mysql_store_result` 得到的 `MYSQL_RES` 地址；
- 返回值：
    - `MYSQL_FIELD` 结构体指针，是一个 `MYSQL_FIELD` 数组，一个 `MYSQL_FIELD` 结构体描述了一列；

`MYSQL_FIELD` 定义如下：

````c
// 结果集中的每一个列对应一个 MYSQL_FIELD
typedef struct st_mysql_field {
  char *name;                 /* 列名-> 字段的名字 */
  char *org_name;             /* Original column name, if an alias */
  char *table;                /* Table of column if column was a field */
  char *org_table;            /* Org table name, if table was an alias */
  char *db;                   /* Database for table */
  char *catalog;              /* Catalog for table */
  char *def;                  /* Default value (set by mysql_list_fields) */
  unsigned long length;       /* Width of column (create length) */
  unsigned long max_length;   /* Max width for selected set */
  unsigned int name_length;
  unsigned int org_name_length;
  unsigned int table_length;
  unsigned int org_table_length;
  unsigned int db_length;
  unsigned int catalog_length;
  unsigned int def_length;
  unsigned int flags;         /* Div flags */
  unsigned int decimals;      /* Number of decimals in field */
  unsigned int charsetnr;     /* Character set */
  enum enum_field_types type; /* Type of field. See mysql_com.h for types */
  void *extension;
} MYSQL_FIELD;
````

函数使用举例：

````c
// 得到存储列数据的数组
MYSQL_FIELD* field = mysql_fetch_fields(res);
// 得到列数量
unsigned int num = mysql_num_fields(res);
// 遍历各个列名
for (int i = 0; i < num; ++i)
{
    printf("column name: %s\n", field[i].name);
}
````



## 获取结果中的记录

### 获取记录数据

`mysql_store_result` 函数得到查询结果，之后需要取出每行，即为每个记录的数据：

````c
typedef char** MYSQL_ROW;
MYSQL_ROW mysql_fetch_row(result);
````

- 参数：
    - `result`：通过 `mysql_store_result` 得到的 `MYSQL_RES` 地址；
- 返回值：
    - 一个 `char**` 指针，一行由多个值组成，每个值使用字符串保存，所以一行的数据是一个字符串数组；
    - 每执行一次就获取一行；即第一次执行获取第一行，第二次执行第二行；如果没有数据了，返回 `NULL`；

### 获取记录长度

每个表格中的数据是一个字符串，可以获取字符串的字节数：

````c
unsigned long* mysql_fetch_length(MYSQL_RES* result);
````

- 参数：
    - `result`：通过 `mysql_store_result` 得到的 `MYSQL_RES` 地址；
- 返回值：
    - 一个长度数组，对应一行中每个数据的长度；
    - 执行 `mysql_fetch_row` 会获取下一行的数据，而 `mysql_fetch_length` 就是获取现在这行的各个数据长度；
    - 如果执行失败，返回 `NULL`；

使用这个两个函数配合，读取一张完整的查询结果：

````c
MYSQL_ROW = row;
unsigned long* lengths;
unsigned int num_fields;

// 获取表格列数
num_fields = mysql_num_fields(result);
// 循环读取表格的每一行
while ( (row = mysql_fetch_row(result)) != NULL )
{
    // 获取次行每个数据的长度
    lengths = mysql_fetch_lengths(result);
    // 输出这行的每一列
    for (int i = 0; i < num_fields; i++)
    {
        printf("%s, %lu    |", row[i], lengths[i]);
	}
    putchar('\n');
}
````



## 资源回收

读取完结果集之后，需要把其中的资源释放：

````c
void mysql_free_result(MYSQL_RES *result);
````

- 参数：`result`：通过 `mysql_store_result` 得到的 `MYSQL_RES` 地址；

需要关系 mysql，也需要释放资源：

```c
void mysql_close(MYSQL *mysql);
```

- 参数：`mysql` ，与 MySQL 通信的实体；



## 字符编码

### 获取字符编码

````c
const char *mysql_character_set_name(MYSQL *mysql) 
````

- 参数：`mysql` ，与 MySQL 服务器通信的实体；
- 返回值：默认字符集；

### 设置字符编码

````c
int mysql_set_character_set(MYSQL *mysql, char *csname);
````

- 参数：
    - `mysql` ：与 MySQL 服务器通信的实体；
    - `csname`：编码字符集合，其中 `"utf8"` 支持中文；



## 事务操作

### 设置事务提交模式

MySQL 默认在执行完语句后提交事务。这样自动提交事务，会使得操作不便；

可以设置用户来手动提交事务：

````c
my_bool mysql_autocommit(MYSQL *mysql, my_bool mode);
````

- 参数：
    - `mysql` ：与 MySQL 服务器通信的实体；
    - `mode`：
        - `1`：启动自动提交模式；
        - `0`：禁止自动提交模式；
- 返回值：
    - 成功设置返回0，否则为非 0；

禁止自动提交后，就需要手动提交事务，或者数据回滚：

### 事务提交

````c
my_bool mysql_commit(MYSQL *mysql);
````

- 参数：`mysql` ：与 MySQL 服务器通信的实体；

- 返回值：成功: 0, 失败: 非0；

### 数据回滚

````c
my_bool mysql_rollback(MYSQL *mysql);
````

- 参数：`mysql` ：与 MySQL 服务器通信的实体；

- 返回值：成功: 0, 失败: 非0；



## 打印错误信息

````c
// 返回错误的描述
const char *mysql_error(MYSQL *mysql);
// 返回错误的编号
unsigned int mysql_errno(MYSQL *mysql);
````



## 实例

在 Windows 下，MySQL 提供的 C 语言 API 头文件 `mysql.h` 保存在下载 MySQL 的路径下的： MySQL\MySQL Server 8.0\include；动态链接库是：MySQL\MySQL Server 8.0\lib\libmysql.dll；

````c
#include <stdio.h>
#include <mysql.h>

int main()
{
    // 1. 初始化连接环境
    MYSQL* mysql = mysql_init(NULL);
    if(mysql == NULL)\
    {
        printf("mysql_init() error\n");
        return -1;
    }

    // 2. 连接数据库服务器
    mysql = mysql_real_connect(mysql, "localhost", "root", "root", 
                               "scott", 0, NULL, 0);
    if(mysql == NULL)
    {
        printf("mysql_real_connect() error\n");
        return -1;
    }

    printf("mysql api使用的默认编码: %s\n", mysql_character_set_name(mysql));

    // 设置编码为utf8
    mysql_set_character_set(mysql, "utf8");

    printf("mysql api使用的修改之后的编码: %s\n", mysql_character_set_name(mysql));

    printf("恭喜, 连接数据库服务器成功了...\n");

    // 3. 执行一个sql语句
    // 查询scott数据库下的dept部门表
    const char* sql = "select * from dept";
    // 执行这个sql语句
    int ret = mysql_query(mysql, sql);
    if(ret != 0)
    {
        printf("mysql_query() a失败了, 原因: %s\n", mysql_error(mysql));
        return -1;
    }

    // 4. 取出结果集
    MYSQL_RES* res = mysql_store_result(mysql);
    if(res == NULL)
    {
        printf("mysql_store_result() 失败了, 原因: %s\n", mysql_error(mysql));
        return -1;
    }

    // 5. 得到结果集中的列数
    int num = mysql_num_fields(res);

    // 6. 得到所有列的名字, 并且输出
    MYSQL_FIELD * fields = mysql_fetch_fields(res);
    for(int i=0; i<num; ++i)
    {
        printf("%s\t\t", fields[i].name);
    }
    printf("\n");

    // 7. 遍历结果集中所有的行
    MYSQL_ROW row;
    while( (row = mysql_fetch_row(res)) != NULL)
    {
        // 将当前行中的每一列信息读出
        for(int i=0; i<num; ++i)
        {
            printf("%s\t\t", row[i]);
        }
        printf("\n");
    }

    // 8. 释放资源 - 结果集
    mysql_free_result(res);

    // 9. 写数据库
    // 以下三条是一个完整的操作, 对应的是一个事务
    // 设置事务为手动提交
    mysql_autocommit(mysql, 0); 
    int ret1 = mysql_query(mysql, "insert into dept values(61, '海军', '圣地玛丽乔亚')");
    int ret2 = mysql_query(mysql, "insert into dept values(62, '七武海', '世界各地')");
    int ret3 = mysql_query(mysql, "insert into dept values(63, '四皇', '新世界')");
    printf("ret1 = %d, ret2 = %d, ret3 = %d\n", ret1, ret2, ret3);

    if(ret1==0 && ret2==0 && ret3==0)
    {
        // 提交事务
        mysql_commit(mysql);
    }
    else
    {
        mysql_rollback(mysql);
    }

    // 释放数据库资源
    mysql_close(mysql);
    
  return 0;
}
````

将 `inlcude ` 文件夹与动态库拷贝到 makefile 当前目录下，就可以进行编译：

````makefile
gcc example.c -I ./include -o example.exe -L ./ -l libmysql 
````



