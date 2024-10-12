#include "SqList.h"
#include<iostream>
using namespace std;

/// <summary>
/// 初始化
/// </summary>
/// <param name="L">线性表变量名</param>
void InitList(SqList& L) {
	L.elem = new ElemType(MAXSIZE);
	L.length = 0;
}

/// <summary>
/// 销毁
/// </summary>
/// <param name="L">线性表变量名</param>
void DestroyList(SqList& L) {
	if (L.elem != nullptr) {
		delete[] L.elem;
		L.elem = nullptr;
	}
	L.length = 0;
}


/// <summary>
/// 查找
/// </summary>
/// <param name="L">线性表变量名</param>
/// <param name="i">所查找的元素索引</param>
/// <param name="e">查找成功后被赋值的变量</param>
/// <returns></returns>
bool GetElem(SqList	L, int i, ElemType& e) {
	if (i >= L.length || i < 0) {
		return false;
		cout << "所查找元素索引不合法" << endl;
	}//索引从0开始
	e = L.elem[i];
	return true;
}

/// <summary>
/// 插入
/// </summary>
/// <param name="L">线性表变量名</param>
/// <param name="i">所插入的位置索引</param>
/// <param name="e">所插入的元素值</param>
/// <returns></returns>
bool ListInsert(SqList& L, int i, ElemType e) {
	if (i >= 0 && i <= L.length && L.length + 1 <= MAXSIZE) {
		for (int j = L.length; j > i; j--) {
			L.elem[j] = L.elem[j - 1];
		}
		L.elem[i] = e;
		L.length++;
		return true;
	}
	cout << "所插入元素索引不合法" << endl;
	return false;
}

/// <summary>
/// 删除
/// </summary>
/// <param name="L">线性表变量名</param>
/// <param name="i">要删除的元素索引</param>
/// <param name="e">所删除的元素值</param>
/// <returns></returns>
bool ListDelete(SqList& L, int i, ElemType& e) {
	if (i >= 0 && i < L.length) {
		e = L.elem[i];
		for (int j = i + 1; j < L.length; j++) {
			L.elem[j - 1] = L.elem[j];
		}
		L.length--;
		return true;
	}
	cout << "所删除元素索引不合法" << endl;
	return false;
}

/// <summary>
/// 打印所有元素
/// </summary>
/// <param name="L">线性表变量名</param>
void Print(SqList L) {
	if (L.length > 0) {
		for (int i = 0; i < L.length; i++) {
			cout << L.elem[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "表为空" << endl;
	}
}

/* 顺序表L有10个整数。设计一个算法，以第一个元素为分界线（基准），将所有小于等于它的元素移到该元素的前面，将所有大于它的元素移到该元素的后面。*/
void QuickSort_L(SqList &L) {
	if (L.elem != nullptr)//表为非空
	{
		ElemType FirstELem = L.elem[0];
		for (int i = 1; i < L.length; i++)
		{
			if (L.elem[i] <FirstELem) {
				ListInsert(L, 0, L.elem[i]);
				ElemType e = 0;
				ListDelete(L, i + 1, e);
			}
		}
	}
}