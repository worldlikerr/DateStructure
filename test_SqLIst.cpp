#include"SqList.h"
#include<iostream>
using namespace std;

int main() {
	SqList L;
	InitList(L);
	Print(L);

	ElemType e=0;
	ListInsert(L, 1, e);//插入不合法
	ListInsert(L, 0, e);
	e = 1;
	ListInsert(L, 0, e);
	e = 2;
	ListInsert(L, 0, e);
	e = 3;
	ListInsert(L, 0, e);
	Print(L);

	GetElem(L, 5, e);//查找不合法
	GetElem(L, 2, e);
	cout << e << endl;

	ListDelete(L, 5, e);//删除不合法
	ListDelete(L, 2, e);
	cout << e << endl;
	Print(L);
	
//	这里DestroyList(L);也会报错，还没找到原因
//	直接Print(L);会报错，说明L的空间已经被释放了

}
