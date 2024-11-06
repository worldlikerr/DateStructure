#include"LinkList.h"
#include<iostream>
using namespace std;

Status MakeNode(Link& p, ELemType e) {
	p = new(nothrow) LNode;
	if (!p) return ERROR;
	p->data = e;
	p->next = nullptr;
	return OK;
}


Status InitList(LinkList& L) {
	L.head = L.tail = nullptr; // 初始化头尾指针为空
	L.len = 0; // 长度初始化为0
	return OK;
}


Status CreateList(LinkList& L, int n) {
	if (!InitList(L))return ERROR;

	ELemType e;
	cin >> e;
	Link temp, pre;
	if (!MakeNode(temp, e))return ERROR;


	L.head->next = temp;
	temp->next = L.tail;
	L.len++;
	pre = temp;
	for (int i = 1; i < n; i++) {
		cin >> e;
		if (!MakeNode(temp, e))return ERROR;

		pre->next = L.tail->next = temp;


		pre = temp;
		L.len++;
	}
	return OK;
}

Status ClearList(LinkList& L) {
	Link current = L.head;
	while (current != nullptr) {
		Link temp = current->next;
		delete current;
		current = temp;
	}
	L.head = L.tail = nullptr;
	L.len = 0;
	return OK;
}


Status LocatePos(LinkList& L, int i, Link& p) {
	if (i > L.len || i < 1)return ERROR;
	for (int j = 1; j <= i; j++) {
		p = L.head->next;
	}
	return OK;
}

Status ListTraverse(LinkList L, Status(*visit)(ELemType)) {
	Link current = L.head; // 假设 L.head 是头节点
	if (current == nullptr || current->next == nullptr) return ERROR; // 检查链表是否为空
	int i = 1;
	while (current != nullptr) { // 遍历到链表末尾
		if (visit(current->data) == ERROR) return ERROR; // 调用访问函数
		current = current->next; // 移动到下一个节点
	}
	return OK;
}

Status ListInsert_L(LinkList& L, int i, ELemType e) {
	if (i < 1 || i > L.len + 1) return ERROR;

	Link newNode = new LNode;
	newNode->data = e;

	if (i == 1) {
		newNode->next = L.head;
		L.head = newNode;
		if (L.len == 0) L.tail = newNode; // 如果链表是空的，更新尾指针
	}
	else {
		Position prev = L.head;
		for (int j = 1; j < i - 1; ++j) {
			if (prev == nullptr) return ERROR; // 防止越界
			prev = prev->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
		if (newNode->next == nullptr) L.tail = newNode; // 更新尾指针
	}

	L.len++;
	return OK;
}



Status ListDelete_L(LinkList& L, int i, ELemType& e) {
	if (i > L.len || i < 1)return ERROR;
	Link  pre;
	pre = L.head;
	for (int j = 1; j < i; j++) {
		pre = pre->next;
	}
	e = pre->next->data;
	pre->next = pre->next->next;

	L.len--;
	return OK;
}
