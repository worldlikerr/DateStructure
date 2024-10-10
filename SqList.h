
#ifndef ARRAY_H
#define ARRAY_H
//头文件保护机制，避免同一个头文件被多次包含，导致重定义错误。
using namespace std;

#define MAXSIZE 10
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
//输出
void Print(SqList L);




#endif