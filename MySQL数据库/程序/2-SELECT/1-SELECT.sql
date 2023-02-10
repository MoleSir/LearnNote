# 使用 USE 语句选择操作的数据库（SQL语言不区分大小写，每个语句必须以　；结尾）
USE sql_store;

# 查询语句
# SELECT 后加上要查询的列，* 代表所有，列就代表某个属性，多个列之间用 ',' 隔开
	# 并且查找到的数据中各个属性的先后顺序，按照 SELECT 后选择的属性顺序排列
    # 可以在使用公式，比如希望将查询到的分数加10，就可以写 points + 10，甚至更加复杂的语句
    # 如果使用公式，那么查询得到的属性名称就是查询代码中写下是公式，比如查询 points + 10
    # 那么得到的结果显示就是 points + 10，当然可以对其改名，将查询的属性后加 AS，再加上你希望设置的名称即可
    # 当查询的出现重复，但我们只希望显示一项，可以在 SELECT 后加 DISTINCT 去重
    # 如果希望名称有空格，就需要加上单引号或者双引号： 'discount factor' / "discount factor"
# FROM　后为要查询的表（此语句不是必要的）
# WHERE 后加上查询条件，这里表示查找 customer_id = 1 （此语句不是必要的）
# ORDER BY 后加上我们希望按照哪个属性给查找到的数据排序 （此语句不是必要的）
# '#' 或者 '--' 代表单行注释
# 以上四个子句的顺序不能改变
# 这里把四个命令写在四行，也可以单独写一行
SELECT last_name, first_name, points + 10 AS 'd i s', (points + 10) * 100 AS discount_factor
From customers
-- WHERE customer_id = 1
ORDER BY first_name;

SELECT DISTINCT state FROM customers
