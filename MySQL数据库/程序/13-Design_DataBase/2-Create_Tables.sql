-- 创建表格
USE sql_store2;
-- 语法：
-- CREATE TABLE 表格名称
DROP TABLE IF EXISTS customers;
-- CREATE TABLE IF NOT EXISTS customers
CREATE TABLE customers
(	
	-- 列名 类型 属性...
		-- PRIMARY KEY 设置为主键
		-- AUTO_INCREAMENT MySQL 自动增长赋值，一般使用在主键中
		-- NOT NULL 不允许空值
		-- DEFAULT 0 默认值为 0
        -- UNIQUE 唯一不可以重复
	customers_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name   VARCHAR(50) NOT NULL,
    last_name    VARCHAR(50) NOT NULL,
    points       INT NOT NULL DEFAULT 0,
    email        VARCHAR(255) NOT NULL UNIQUE
);