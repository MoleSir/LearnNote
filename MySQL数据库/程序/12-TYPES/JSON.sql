-- JSON
USE sql_store;
UPDATE products
-- 创建 JOSON 对象，在 '' 内直接写 JSON 代码
SET properities = '
{
	"dimensions": [1, 2, 3], 
    "weight": 10,
    "manufacturer": { "name": "sony" }
}
'
WHERE product_id = 1;

UPDATE products
-- 创建 JOSON 对象，JSON_OBJECT 函数
SET properities = JSON_OBJECT(
	'weight', 10, 
    'dimensions', JSON_ARRAY(1, 2, 3),
	'manufacturer', JSON_OBJECT('name', 'sony')
)
WHERE product_id = 1;


SELECT * 
FROM products;

SELECT 
	product_id,
    -- JSON_EXTRACT 取出 weight 键对应的值
	JSON_EXTRACT(properities, '$.weight') AS weight
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    -- 使用 -> 取出 weight 键对应的值
    properities -> '$.weight' AS weight
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    -- 使用 -> 取出 dimensions 键对应的值，是一个数组，可以对数组使用 [] 索引获取某个值，从 0 开始索引
    properities -> '$.dimensions[1]' 
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    -- 使用 -> 取出 manufacturer 键对应的值，一个 JSON 对象
    properities -> '$.manufacturer'
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    --  manufacturer 键对应的值，一个 JSON 对象，还可以继续使用 . 取出其值
    properities -> '$.manufacturer.name'
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    --  ->> 不显示字符串的引号 
    properities ->> '$.manufacturer.name'
FROM products
WHERE product_id = 1;

SELECT 
	product_id,
    --  ->> 不显示字符串的引号 
    properities ->> '$.manufacturer.name'
FROM products
WHERE properities ->> '$.manufacturer.name' = 'sony';

-- 修改 JSON 对象
UPDATE products
-- JSON_SET 函数
SET properities = JSON_SET(
	-- 参数一指定 JSON 对象
    properities,
    -- 修改
    '$.weight', 20,
    -- 增加
    '$.age', 10
)
WHERE product_id = 1;

-- 删除 JSON 对象的键值对
UPDATE products
-- JSON_REMOVE 函数，返回一个新的 JSON 对象
SET properities = JSON_REMOVE(
	-- 参数一指定 JSON 对象
    properities,
    -- 指定参数的键 
    '$.age'
)
WHERE product_id = 1;