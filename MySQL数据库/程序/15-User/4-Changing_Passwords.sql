-- 修改密码
-- 为别人修改密码 
SET PASSWORD FOR john = '1234';
-- 修改当前用户，哪个用户执行就修改谁的密码
SET PASSWORD = '123456';