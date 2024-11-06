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
	
	ListInsert_L(L, 1, 1);


	ListInsert_L(L, 2, 2);
	ListInsert_L(L, 3, 3);
	ListInsert_L(L, 4, 4);
	ListTraverse(L, Print);
}

