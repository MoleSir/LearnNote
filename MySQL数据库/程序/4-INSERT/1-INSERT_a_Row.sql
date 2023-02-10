-- 单行插入 --
-- INSERT INTO
USE sql_store;

INSERT INTO customers
-- 在 VALUES 后按照 customers 表格的属性顺序给出值，如果某些列有默认值，可以用 DEFAULT 代替
-- MySQL 会把默认值填入 
VALUES (
	DEFAULT, 
	'Ye', 
    'Cheng', 
    '2002-07-16', 
    DEFAULT, -- 或者直接 NULL
    'China',
    'NingDe',
    'SN',
    DEFAULT);
    
-- 在表格后面选择要插入的新行的哪些属性，必填的属性不能遗漏
-- 这样我们就可以在 VALUES 后对应自己写的属性顺序，填入值
-- 如果在表格名称后没有填上有默认值的属性，这样可以不用写 DEFAULT，
-- 表格后我们给出的属性不一定按顺序，但给值的时候需要跟这里一一对应 
INSERT INTO customers (
	first_name,
    last_name,
    birth_date,
    address,
    city,
    state)
VALUES(
	'Xu', 
    'XuTing', 
    '2002-02-14', 
    'China',
    'NingDe',
    'SN');
    
-- 这里的 customers_id 被设置为主键，不能重复，并且这是一个 AI 属性，既当我们插入一个新行
-- 如果我们使用 DEFAULT 来赋值 customer_id 属性，MySQL 会将这个属性设置为递增的值，这里的就是 1，2，3，4，，，
-- 插入一个新的，就递增一个 id 幅值给新行； 