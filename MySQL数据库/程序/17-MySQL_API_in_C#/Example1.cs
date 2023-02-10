using System;
using MySql.Data;
using MySql.Data.MySqlClient;
using System.Data;
using System.Collections.Generic;


namespace MySQLApplication
{
    struct Product
    {
        public Product(int i, string n, int q, decimal p)
        {
            this.id = i;
            this.name = n;
            this.quantity = q;
            this.price = p;
        }
        public void Print()
        {
            Console.Write("ID: {0}\t\t\t", this.id);
            Console.Write("Name: {0}\t\t\t", this.name);
            Console.Write("Quantity: {0}\t\t\t", this.quantity);
            Console.WriteLine("Price: {0}", this.price);
        }
        int id;
        string name;
        int quantity;
        decimal price;    
    }

    class Program
    {
        static void Main()
        {
            // 1. 创建 MySQL 连接对象
            string connectStr = "server=localhost;user=root;database=sql_store;port=3306;password=xyt020716yc!";
            MySqlConnection mysql = new MySqlConnection(connectStr);
            // 开启
            try
            {
                mysql.Open();
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

            // 2. 创建无查询命令
            string sql2 = "INSERT INTO products VALUES(DEFAULT, 'zzz', 100000, 10.0);";
            MySqlCommand cmd2 = new MySqlCommand(sql2, mysql);
            // 3. 执行
            cmd2.ExecuteNonQuery();

            // 2. 创建命令
            string sql1 = "SELECT * FROM products;";
            MySqlCommand cmd1 = new MySqlCommand(sql1, mysql);
            
            // 3. 执行命令
            MySqlDataReader reader = cmd1.ExecuteReader();
            List<Product> products = new List<Product>();
            while (reader.Read())
            {
                int id = reader.GetInt32("product_id");
                string name = reader.GetString("name");
                int quantity = reader.GetInt32("quantity_in_stock");
                decimal price = reader.GetDecimal("unit_price");
                products.Add(new Product(id, name, quantity, price));
            }

            foreach (Product p in products)
                p.Print();

            // 4. 执行事务
            MySqlTransaction transaction = mysql.BeginTransaction();
            try
            {
                // ...
            }
            catch(MySqlException ex)
            {
                Console.WriteLine(ex.Message);
                transaction.Rollback();
                mysql.Close();
            }
            finally
            {
                if (mysql.State != ConnecttionState.Closed)
                {
                    transaction.Commit();
                }
            }

            mysql.Close();
        }
    }
}