-- 赋予权限
-- 1: 仅仅创建用户，允许其连接数据库，读写数据，不能创建表格、修改表格
CREATE USER moon_app@127.0.0.1 IDENTIFIED BY '1234';
GRANT SELECT, INSERT, UPDATE, DELETE, EXECUTE
ON sql_store.*
TO moon_app@127.0.0.1;


-- 2: 管理员，可以修改数据库，创建新表格等；
GRANT ALL
-- *.*
ON *.*
TO john;