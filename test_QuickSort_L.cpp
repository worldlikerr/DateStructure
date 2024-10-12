#include"SqList.h"
#include<iostream>
#include<random>
using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd()); // 使用Mersenne Twister引擎
	uniform_int_distribution<> dist(1, 100); // 生成1到100之间的随机整数

	SqList L;
	InitList(L);
	ElemType e = 0;

	for (int i = 0; i < 20; i++)
	{
		e = dist(gen);
		ListInsert(L, 0, e);
	}
	
	cout << "排序前" << endl;
	Print(L);
	QuickSort_L(L);
	cout << "排序后" << endl;
	Print(L);
}