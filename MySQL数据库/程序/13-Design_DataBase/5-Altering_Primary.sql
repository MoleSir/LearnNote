-- 修改主键
ALTER TABLE orders
	ADD PRIMARY KEY (order_id),
    DROP PRIMARY KEY;
        