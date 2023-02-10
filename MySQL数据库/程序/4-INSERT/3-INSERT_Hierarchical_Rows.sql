-- 插入分层数据 --
-- 有时若干个表之间存在着关系：
-- 比如，orders 表保存每笔订单的信息， 有一个 order_id 属性
-- 但每个订单都买了些什么，这些信息保存在了 order_items 表里
-- 那里记录了每笔订单里面都有什么产品，所以在 order_items 里面，也有一个 order_id 属性，并且这个属性不一定要独立，因为每个订单可以有多个产品
-- 与 orders 里的对应，我们可以将两个表格 JOIN 起来；  
-- 那么如果我们向 orders 插入一个新行，应该也要向 order_items 插入若干行（行数取决于这笔订单的产品数量）
-- 这看起来没什么，但问题是，在 orders 中，order_id 是 MySQL 按顺序自己填入的，我们并不知道
-- 那么如何在向 order_items 插入行时填入 order_id 信息呢
-- 这就需要使用到： LAST_INSERT_ID()，它保存最近一个 MySQL 为我们填入的值
INSERT INTO orders (customer_id, order_date, status)
VALUES (1, '2019-01-02', 1);

-- 向 order_items 插入
INSERT INTO order_items
VALUE
	(LAST_INSERT_ID(), 1, 1, 2.95),
    (LAST_INSERT_ID(), 2, 1, 3.98)