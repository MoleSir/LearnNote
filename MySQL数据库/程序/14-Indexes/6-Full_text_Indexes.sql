-- 全文索引
USE sql_blog;
SELECT *
FROM posts
WHERE title LIKE '%react redux%' OR 
	  body LIKE '%react redux%';
      
CREATE FULLTEXT INDEX idx_title_body ON posts (title, body);

-- 计算相关性
SELECT *, MATCH(title, body) AGAINST('react redux')
FROM posts
-- 选出标题或正文中包含 'react' 或者 'redux' 的
WHERE MATCH(title, body) AGAINST('react redux');

-- BOOLEAN 搜索
SELECT *
FROM posts
-- 选出标题或正文中包含 'react' 或者 'redux' 的
-- 加 - 号表示不能出现这个单词，+ 表示必须出现
WHERE MATCH(title, body) AGAINST('react -redux +form' IN BOOLEAN MODE);