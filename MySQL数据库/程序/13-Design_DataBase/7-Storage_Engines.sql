-- 存储引擎 
-- MySQL 有几个不同的存储引擎，这些引擎决定了数据如何被存储，以及哪些功能可供我们使用
-- 显示存储引擎
SHOW ENGINES;
-- 默认 InnoDB

-- 修改表格的存储引擎
ALTER TABLE customers
ENGINE = InnoDB;