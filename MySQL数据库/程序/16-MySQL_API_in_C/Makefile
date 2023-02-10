# 编译器设置
CC := gcc
# 头文件目录
CFLAGS := -I ./include
CPPFLAGS := -I ./include
# 链接库
LIB := -L ./ -l libmysql

# 伪目标
.PHYON: example, cppMySql

example: example.c
	$(CC) $^ $(CFLAGS) -o example.exe $(LIB) 

cppMySql: cppMySql.cpp
	g++ $^ $(CPPFLAGS) -o cppMySql.exe $(LIB)
