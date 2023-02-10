-- 删除过程
USE sql_invoicing;
DROP PROCEDURE get_clients;

-- 删除后再次执行会报错，因为找不到这个过程
-- 可以使用 IF EXISTS
DROP PROCEDURE IF EXISTS get_clients;