#include"LinkList.h"
#include<iostream>
using namespace std;

Status Print(ELemType data) {
	cout << data << " "; // 打印节点的数据
	cout << endl;
	return OK;
}

int main() {
	LinkList L;
	InitList(L);
	CreateList(L, 5);

//	cout << L.len << endl;
//	ListTraverse(L, Print);

	//ListInsert_L(L, 5, 17);
	//ListInsert_L(L, 3, 17);
	//ListTraverse(L, Print);

	ELemType e = 0;
	ListDelete_L(L, 5, e);

	ListTraverse(L, Print);
	ListDelete_L(L, 2, e);
	

	ListTraverse(L, Print);
}