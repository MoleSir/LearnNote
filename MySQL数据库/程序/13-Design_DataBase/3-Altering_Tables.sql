-- 修改已经存在的表格
USE sql_store2;
-- ALTER TABLE 表名
-- 	添加新列
-- 	ADD (COLUMN) 新列名 类型 (属性) (位置),
--  ADD (COLUMB)... 					 ,
--  修改已经存在的列
--  MODIFY (COLUMN)	需要修改的列名 新类型 （新属性）,
--  删除
--  DROP (COLUMN) 删除的列名
--  ...;

ALTER TABLE customers
	-- 在 first_name 属性之后
	ADD COLUMN last_name VARCHAR(50) NOT NULL AFTER first_name,
    ADD city      		 VARCHAR(50) NOT NULL,
    MODIFY COLUMN first_name VARCHAR(55) DEFAULT ' ',
    DROP points;
    