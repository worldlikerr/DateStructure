#include"BiTree.h"
#include<iostream>
using namespace std;
Status print(TElemType e) {
	cout << e << " ";
	return OK;
}
int main() {
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T, print);
	cout << endl;
	InOrderTraverse(T, print);
	cout << endl;
	PostOrderTraverse(T, print);
	cout << endl;
	LevelOrderTraverse(T, print);
}