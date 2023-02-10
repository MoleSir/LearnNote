-- WITH CHECK OPTION 可以防止视图的某项由删除，当修改或删除视图可能导致
-- 其中的某个行消失，会报错

-- 这里还可以了解到视图的创建逻辑，
-- 比如我们对选择这张 invoices_with_balance 视图做修改，把 invoice_id 为 2 的
-- 表项中的 invoice_total 改为与 payment_total 相同：
UPDATE invoices_with_balance
SET invoice_total = payment_total
WHERE invoice_id = 2;
-- 执行完后，看起来只是把 2 号的invoice_total = payment_total，但是视图中的这个项目却消失了 
-- 这是因为我们更新了表格，先修改了 2 号的 invoice_total 属性
-- 然后再去执行产生 invoices_with_balance 视图的代码，在那里我们没有将 invoice_total - payment_total < 0 的项加入视图
-- 所以 2 号也不加入，导致 2 号被删除；
-- 可以得知，视图果然只是一段代码，我们使用的时候会创建，并不是真正存在数据
-- 并且修改或删除视图还会对原数据造成影响
-- PS：在这个例子中，2 号没有被删除，但是对它的修改确实发生了

-- 创建视图时，在最后加上  WITH CHECK OPTION，当视图的某行可能被删除时，报错
-- 使用 WITH CHECK OPTION 再次创建视图，执行下面的程序报错：
UPDATE invoices_with_balance
SET invoice_total = payment_total
WHERE invoice_id = 4;
