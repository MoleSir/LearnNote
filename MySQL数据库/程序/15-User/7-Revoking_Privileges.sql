-- 撤销特权
-- 给 moon_app 创建视图的权力
GRANT CREATE VIEW
ON sql_store.*
TO moon_app;

-- 撤销 moon_app 创建视图的能力
REVOKE CREATE VIEW
ON sql_store.*
FROM moon_app;