﻿# 数据机构的实现（CPP)  
## 项目说明
大二的数据机构作业，上传到GitHub上作一个记录，上传的代码文件夹无分类，很乱，但实际上我本地的VS是有分类的
后期看看有时间分类一下。GitHub地址：https://github.com/worldlikerr/DateStructure?tab=readme-ov-file
## 更新记录
### 十月十日
+ 创建项目，初始化项目结构  
+ 添加`.gitignore`文件忽略某些导致无法推送的文件
( .vs 文件夹下的某些文件无法被访问或处理（权限被拒绝），导致 Git 操作失败。)
+ 一开始无法运行，想要在原来的基础上创建C++控制台项目，直接复制`test_SqList.cpp`文件内容过去但运行报错，这是一个链接 [Markdown语法](https://markdown.com.cn)。
可按照该方法来可解决问题[简单使用VS来管理数据结构的代码(C语言版)]：https://blog.csdn.net/qq_30075345/article/details/108454696
 VS无法找到不在右边解决方案资源管理器窗口直接创建的文件，但可通过手动设置寻找到对应目录，但过程还是很麻烦
### 十月十一日
+ 完善`test_SqList.cpp`代码