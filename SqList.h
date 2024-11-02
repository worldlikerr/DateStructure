//顺序表
#ifndef ARRAY_H
#define ARRAY_H
//头文件保护机制，避免同一个头文件被多次包含，导致重定义错误。
using namespace std;

#define MAXSIZE 50
typedef int ElemType;

typedef struct
{
	ElemType* elem;
	int length;
} SqList;

//初始化
void InitList(SqList& L);
//销毁
void DestroyList(SqList& L);
//查找
bool GetElem(SqList	L, int i, ElemType& e);
//插入
bool ListInsert(SqList& L, int i, ElemType e);
//删除
bool ListDelete(SqList& L, int i, ElemType& e);
//打印
void Print(SqList L);
/* 顺序表L有10个整数。设计一个算法，以第一个元素为分界线（基准），将所有小于等于它的元素移到该元素的前面，将所有大于它的元素移到该元素的后面。*/
void QuickSort_L(SqList& L);




#endif