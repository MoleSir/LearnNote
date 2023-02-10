/* 使用C++对C语言的MySQL API进行封装 */
#include <mysql.h>
#include <iostream>

namespace MySqlAPI
{
    /* MySQL服务器连接类 */
    class MySql
    {
        using cString = const char*;
    public:
        // 构造函数
        MySql(cString host, cString user, cString passwd, cString db, unsigned int port, cString unix_socket, unsigned long clinet_flag, cString character)
            : _mysql(NULL), _queryRes(NULL)
        {
            // 初始化连接环境
            std::cout << "initial MySQL environment...\n";
            this->_mysql = mysql_init(NULL);
            if (this->_mysql == NULL)
            {
                std::cout << "mysql_init failed\n";
                exit(0);
            }
            // 连接数据服务器
            std::cout << "connect to MySQL server...\n";
            this->_mysql = mysql_real_connect(
                this->_mysql,
                host,
                user,
                passwd,
                db,
                port, 
                NULL,
                0
            );
            if (this->_mysql == NULL)
            {
                std::cout << "mysql_real_connect failed!\n";
                exit(0);
            }
            // 设置编码方式
            std::cout << "set mysql character way...\n";
            mysql_set_character_set(this->_mysql, character);
            
            std::cout << "connect MySQL server successfuly!\n";
        }
        
        // 禁止拷贝
        MySql(const MySql& that) = delete;
        MySql& operator = (const MySql& that) = delete;

        // 移动
        MySql(MySql&& that) : _mysql(that._mysql), _queryRes(that._queryRes)
        {
            that._mysql = NULL;
        }
        MySql& operator = (MySql&&) = delete;

        // 析构函数
        ~MySql()
        {
            if (!this->_mysql)
                mysql_close(this->_mysql);
        }

        // 执行无查询语句
        int ExecuteNonQuery(cString query)
        {
            return mysql_query(this->_mysql, query);
        }

        // 执行有查询语句
        int ExecuteQuery(cString query)
        {
            int ret = mysql_query(this->_mysql, query);
            // 获取结果
            this->_queryRes = mysql_store_result(this->_mysql);
            if (this->_queryRes == NULL)
            {
                std::cout << "mysql_store_result failed, because " << mysql_error(this->_mysql) << std::endl;
                return -1;
            }
            return ret;
        }

        // 获取表头数组
        MYSQL_FIELD* GetFields() const
        {
            return mysql_fetch_fields(this->_queryRes);
        }

        // 获取下一行的数据
        MYSQL_ROW GetNextRow()
        {
            return mysql_fetch_row(this->_queryRes);
        }

        // 获取列数
        int GetFieldsNum() const
        {
            return mysql_num_fields(this->_queryRes);
        }

        // 遍历查询结果，仅仅打印
        int TraverseQueryResult()
        {
            // 检查是否存在查询数据
            if (this->_queryRes == NULL)
            {
                std::cout << "no query result!\n";
                return -1;
            }

            // 打印表头
            MYSQL_FIELD* fields = mysql_fetch_fields(this->_queryRes);
            int fieldNum = mysql_num_fields(this->_queryRes);
            for (int i = 0; i < fieldNum; ++i)
                std::cout << fields[i].name << "\t\t\t";
            putchar('\n');
           
            // 遍历
            MYSQL_ROW row = NULL;
            while ( (row = mysql_fetch_row(this->_queryRes)) != NULL )
            {
                for (int i = 0; i < fieldNum; ++i)
                    std::cout << row[i] << "\t\t\t";
                putchar('\n');
            }

            // 释放资源
            mysql_free_result(this->_queryRes);
            this->_queryRes = NULL; 
            return 0;
        }
        
        // 释放资源
        void FreeResult()
        {
            if (this->_queryRes != NULL)
                mysql_free_result(this->_queryRes);
            this->_queryRes = NULL;
        }

        // 手动关闭连接
        void Close()
        {
            if (!this->_mysql)
                mysql_close(this->_mysql);
            this->_mysql = NULL;
        }

        // 开启事务
        void StartTransaction()
        {
            // 设置手动提交
            mysql_autocommit(this->_mysql, 0);
        }

        // 设置是否自动提交
        void SetAutoCommit(int mode)
        {
            mysql_autocommit(this->_mysql, mode);
        }

        // 提交事务
        void Commit()
        {
            mysql_commit(this->_mysql);
            mysql_autocommit(this->_mysql, 1);
        }

        // 数据回滚
        void Rollback()
        {
            mysql_rollback(this->_mysql);
            mysql_autocommit(this->_mysql, 1);
        }

    private:
        MYSQL* _mysql;
        MYSQL_RES* _queryRes;
    };
}


int main()
{
    using namespace MySqlAPI;
    MySql mysql(
        "localhost",
        "root",
        "xyt020716yc!",
        "sql_store",
        3306,
        NULL,
        0,
        "utf8"
    );

    // 执行查询
    mysql.ExecuteQuery("SELECT * FROM products");
    mysql.TraverseQueryResult();

    // 开启事务
    mysql.StartTransaction();
    int ret1 = mysql.ExecuteNonQuery("INSERT INTO products VALUES(DEFAULT, 'hhhhhhhhh', 250, 3.14)");
    int ret2 = mysql.ExecuteNonQuery("UPDATE products SET quantity_in_stock = 100 WHERE name = 'Broom - Push'");
    int ret3 = mysql.ExecuteNonQuery("UPDATE products SET quantity_in_stock = 1000 WHERE name = 'Longan'");
    if (ret1 == 0 && ret2 == 0 && ret3 == 0)
    {   
        // 提交
        std::cout << "commit!\n";
        mysql.Commit();
    }
    else
    {
        // 回滚
        std::cout << "rollback!\n";
        mysql.Rollback();
    }

    mysql.ExecuteQuery("SELECT * FROM products");
    mysql.TraverseQueryResult();

    mysql.Close();

    return 0;
}