-- 创建用户
-- 数据保持在 MySQL 的服务器端，如果应用程序或者 web 希望读取数据，需要创建一个用户
-- 并且赋予这个用户一定的权限，比如可以读取数据、但不可以修改
-- 或者当数据库需要多人维护，虚继创建一个管理员一起管理整个 MySQL 服务器

-- 创建用户
-- 指定用户只能从某个 ip 连接数据库
CREATE USER john1@127.0.0.1;
-- 指定用户只能从服务器所在的主机连接数据库
CREATE USER john2@localhost;
-- 指定用户只能从某个域名下的主机登录
CREATE USER john3@codewithmosh.com;
-- 不指定用户登录主机，可以从任何 ip 连接数据库
CREATE USER john4;
-- 创建用户并且设定密码
CREATE USER john IDENTIFIED BY '123456';