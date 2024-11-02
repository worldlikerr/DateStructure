//单链表
//该链表的实现存在很大问题，主要是插入部分，须重构
#pragma once


#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef char ELemType;
typedef int Status;


//结点定义
typedef struct LNode {
	ELemType data;
	struct LNode* next;
} *Link, * Position;

//链表定义
typedef struct {
	Link head, tail;
	int len;
}LinkList;

/// <summary>
/// 分配由p指向e的结点
/// </summary>
/// <param name="p">分配p的结点空间</param>
/// <param name="e">p所指结点</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status MakeNode(Link& p, ELemType e);

/// <summary>
/// 释放p所指结点
/// </summary>
/// <param name="p">结点p</param>
void FreeNode(Link& p);

/// <summary>
/// 初始化表
/// </summary>
/// <param name="L">表名</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status InitList(LinkList& L);

/// <summary>
/// 销毁
/// </summary>
/// <param name="L">表名</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status DestroyList(LinkList& L);

/// <summary>
/// 重置为空表
/// </summary>
/// <param name="L"></param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status ClearList(LinkList& L);

/// <summary>
/// 创建
/// </summary>
/// <param name="L">表名</param>
/// <param name="n">元素个数</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status CreateList(LinkList& L, int n);

/// <summary>
/// 定位
/// </summary>
/// <param name="L">表名</param>
/// <param name="i">所查询结点的索引</param>
/// <param name="p">指向i的结点</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status LocatePos(LinkList& L, int i, Link& p);

/// <summary>
/// 遍历
/// 从前往后
/// </summary>
/// <param name="L">表名</param>
/// <param name="visit">每个元素调用visit（）函数</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status ListTraverse(LinkList L, Status(*visit)(ELemType));

/// <summary>
/// 插入
/// </summary>
/// <param name="L">表名</param>
/// <param name="i">所插入的位置索引,起始元素位置为1</param>
/// <param name="e">所插入的元素值</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status ListInsert_L(LinkList& L, int i, ELemType e);

/// <summary>
/// 删除
/// </summary>
/// <param name="L">表名</param>
/// <param name="i">所删除的位置索引</param>
/// <param name="e">所删除的元素值</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status ListDelete_L(LinkList& L, int i, ELemType& e);

