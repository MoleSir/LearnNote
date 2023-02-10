# LIMIT 使用
# 只希望查到若干项，使用 lIMIT 来限制查询的个数

# 只查 3 项
SELECT *
FROM sql_store.customers
# 如果限制的数量比总量还多，就没有意义
LIMIT 3;

# 加入偏移量
SELECT *
FROM sql_store.customers
# 6 表示偏移量，跳过前 6 个记录，返回 3 个
LIMIT 6, 3;