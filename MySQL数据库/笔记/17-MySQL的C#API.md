# MySQL 的 C# API

使用 MySQL API 之前，需要包含 `MySql.Data` 、 `MySql.Data.MySqlClient` 、`System.Data`；

C# 编译器没有自带这些库文件，需要上网下载 MySql.Data.dll，并且在 C# 编译命令增加对动态库的引用；

C# 操作 MySQL 的操作流程：

1. 使用 `MySqlConnection` 对象连接数据库；
2. 建立 `MySqlCommand` 对象，执行 SQL 语句；
3. 对 SQL 语句执行后的结果进行操作；
    - 用 `MySqlDataReader` 一行一行读取数据集；
    - 使用 `DataSet` 联合 `DataAdapter` 操作数据库；



## `MySqlConnection` 类

`MySqlConnection` 类用来连接 MySQL 数据库；

### 构造函数

#### 字符串作参数

````c#
MySqlConnection(string connstr);
````

参数是一个描述连接信息的字符串，需要包含以下信息：

- `server`：服务器 IP，`localhost` 代表连接本地的 MySQL 服务器；
- `port`：MySQL 服务器的端口，默认 3306；
- `user`：连接 MySQL 服务器的用户名；
- `password`：用户登录密码；
- `database`：数据库名称；
- `charset`：编码方式，使用 `utf8` 可支持中文；

创建 `MySqlConnection`  对象举例：

````c#
string connStr = "server = localhost; user = root; database = students; port = 3306; password = ***"
MySqlConnection conn = new MySqlConnection(connStr) ;
try{conn.Open();}
catch(Exception ex){Console.WriteLine(ex.ToString());}
````

#### `MySqlConnectionStringBuilder` 对象作参数

````c#
MySqlConnection(MySqlConnectionStringBuilder);
````

写字符串可能会写错，并且不美观，可以使用 `MySqlConnectionStringBuilder` 对象，其中保存的就是连接的各个信息；

创建 `MySqlConnection`  对象举例：

````C#
MySqlConnectionStringBuilder builder = new MySqlConnectionStringBuilder();
//用户名
builder.UserID = "root";
//密码
builder.Password = "root";
//服务器地址
builder.Server = "localhost";
//连接时的数据库
builder.Database = "lcz";
//定义与数据连接的链接
MySqlConnection connection = new MySqlConnection(builder.ConnectionString);
````

### `Open` 方法

通过调用 `SqlConnection` 对象的 `Open`  方法建立数据库连接，与 `try` `catch` 配合使用；

````c#
try 
{	
	conn.Open();
}
catch(Exception ex)
{
	Console.WriteLine(ex.ToString());
}
````

###  `Close` 方法

使用完数据库后，关闭

````c#
conn.Close();
````



## `MySqlCommand` 类

### 构造函数

`MySqlCommad` 对象保存一个 MySQL 命令，构造函数需要两个参数：

- MySQL 命令：一条 SQL 语句，直接保存在字符串中，表示执行的命令；
- `MySqlConnection` 对象：表示操作的数据库；

````c#
string sql = "SELECT * from writer;" ;
MySqlCommand cmd = new MySqlCommand(sql, conn) ;
````

---

### `ExecuteReader` 方法

调用 `MySqlCommand` 类的 `ExecuteReader` 方法，执行需要返回信息的查询的命令；

````c#
MySqlDataReader reader = cmd.ExecuteReader();
````

函数返回一个 `MySqlDataReader` 对象，保存查询结果；

#### `MySqlDataReader` 类

获取 `MySqlDataReader` 对象后，需要执行对象的 `Read()` 方法，每调用一次 `MySqlDataReader` 对象指向下一行数据，直到所有记录遍历完毕后，`Read()` 方法返回 `Fasle`，可以使用 `while()` 循环获取表格数据；

````c#
while (reader.Read()) { ... }
````

#### 索引器

可以把 `MySqlDataReader` 对象理解为一个字典，保存着表格中某行，列名与数据的映射；

可以使用 `[]`  索引器获取数据，`[]` 中写列名，得到对应的数据（字符串），需要自己做类型转换；

```c#
while (reader.Read())
{
    int id = (reader["Id"]).ToInt32();
    string name = reader["Name"].ToString();
    string age = reader["Age"].ToString();
}
```

#### 类型转换方法

还可以调用 `MySqlDataReader` 中封装好的类型转换方法，在方法参数中写上类名，直接可以返回数据；比如 `GetInt32()`、`GetString`、`GetDecimal` 等；

````c#
while (reader.Read())
{	
    // 使用索引器
    int id = reader.GetInt32("Id");
    string name = reader.GetString("Name");
    string age = reader.GetString("Age");
}
````

---

### `ExecuteNonQuery` 方法

调用 `MySqlCommand` 类的 `ExecuteNonQuery` 方法，执行不需要返回信息的增、删、改命令；

执行过程很简单，创建好 `MySqlCommand` 对象后，直接执行即可；



## `MySqlTransaction` 类

调用 `MySqlConnection` 对象的 `BeginTransaction` 方法获得一个事务 `MySqlTransaction` 对象；

表示创建一个事务，之后的语句不会直接提交，直到调用 `MySqlTransaction` 对象的 `Commit` 方法提交事务，或者调用 `Rollback` 方法回滚数据；

可以把事务的执行放置在 `try` 中，如果抛出异常就回滚数据，否则正常提交；

````c#
MySqlTransaction transaction = conn.BeginTransaction();
try
{ ... }
catch(MySqlException ex) {
	Console.WriteLine(ex.Message);
	transaction.Rollback();//事务ExecuteNonQuery()执行失败报错，username被设置unique
    // 关闭 MySQL 数据库连接
	conn.Close();
}
finally {
    // 根据 conn 状态判断是否执行成功
    if(conn.State != ConnectionState.Closed)
    {
    	transaction.Commit();
   		conn.Close();
    }
}
````

