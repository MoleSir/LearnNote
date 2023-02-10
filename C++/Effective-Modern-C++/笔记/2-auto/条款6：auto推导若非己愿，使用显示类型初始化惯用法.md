# 条款 6：`auto`推导若非己愿，使用显式类型初始化惯用法

​		Item 6: Use the explicitly typed initializer idiom when `auto` deduces undesired types

## 请记住

- 不可见的代理类可能会使`auto`从表达式中推导出“错误的”类型
- 显式类型初始器惯用法强制`auto`推导出你想要的结果