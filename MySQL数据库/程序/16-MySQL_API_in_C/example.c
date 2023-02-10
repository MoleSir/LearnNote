/* MySQL的C语言API使用 */
#include <mysql.h>
#include <stdio.h>

int main(void)
{
    // 1. 初始化连接环境
    printf("initial MySQL environment...\n");
    MYSQL* mysql = mysql_init(NULL);
    if (mysql == NULL)
    {
        printf("mysql_init failed!\n");
        return -1;
    }

    // 2. 连接数据服务器
    printf("connect to MySQL server...\n");
    mysql = mysql_real_connect(
        mysql,
        "localhost",
        "root",
        "xyt020716yc!",
        "sql_store",
        3306,
        NULL,
        0
    );
    if (mysql == NULL)
    {
        printf("mysql_real_connect failed!\n");
        return -1;
    }

    printf("mysql api's code way: %s\n", 
           mysql_character_set_name(mysql));
        
    // 设置为 utf8
    mysql_set_character_set(mysql, "utf8");

    printf("after modified, mysql api's code way: %s\n", 
           mysql_character_set_name(mysql));

    printf("connect MySQL server successfuly!\n");

    // 3. 执行 SQL 语句
    const char* sql = "SELECT * FROM products";
    printf("execute SQL query...\n");
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("mysql_query failed, because %s\n",
               mysql_error(mysql));
        return -1;
    }

    // 4. 取出执行结果
    MYSQL_RES* res = mysql_store_result(mysql);
    if (res == NULL)
    {
        printf("mysql_store_result failed, because %s\n",
               mysql_error(mysql));
        return -1;
    }

    // 5. 得到结果列数
    int num = mysql_num_fields(res);

    // 6. 获取表头
    MYSQL_FIELD* fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i)
        printf("%s\t\t\t", fields[i].name);
    putchar('\n');

    // 7. 遍历结果
    MYSQL_ROW row;
    while ( (row = mysql_fetch_row(res)) != NULL )
    {
        for (int i = 0; i < num; ++i)
            printf("%s\t\t\t", row[i]);
        putchar('\n');
    }

    // 8. 释放资源 - 结果
    mysql_free_result(res);
    
    // 9. 写数据库
    // 设置事务为手动提交
    mysql_autocommit(mysql, 0);
    // 执行命令
    int ret1 = mysql_query(mysql, 
              "INSERT INTO products VALUES(DEFAULT, 'hhhhhhhhh', 250, 3.14)");
    int ret2 = mysql_query(mysql, 
              "UPDATE products SET quantity_in_stock = 100 WHERE name = 'Broom - Push'");
    int ret3 = mysql_query(mysql,
              "UPDATE products SET quantity_in_stock = 1000 WHERE name = 'Longan'");
    // 根据返回值决定是否提交事务
    if (ret1 == 0 && ret2 == 0 && ret3 == 0)
    {   
        // 提交
        printf("commit!\n");
        mysql_commit(mysql);
    }
    else
    {
        // 回滚
        printf("rollback!\n");
        mysql_rollback(mysql);
    }

    // 释放数据库
    mysql_close(mysql);

    return 0;
}