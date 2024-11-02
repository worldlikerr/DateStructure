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
	L.head = L.tail = new LNode;
	if (!L.head || !L.tail)return ERROR;
	L.head->next = L.tail->next = nullptr;
	L.len = 0;
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

	current = current->next; // 从第一个有效节点开始遍历
	while (current != nullptr) { // 遍历到链表末尾
		if (visit(current->data) == ERROR) return ERROR; // 调用访问函数
		current = current->next; // 移动到下一个节点
	}
	return OK;
}

Status ListInsert_L(LinkList& L, int i, ELemType e) {
	if (i < 1 || i > L.len + 1) return ERROR;

	Link p;
	if (!MakeNode(p, e)) return ERROR;

	// 插入在链表头部
	if (i == 1) {
		p->next = L.head;
		L.head = p;
		if (L.len == 0) L.tail = p;  // 若链表原本为空，更新尾指针
	}
	else {
		Link pre = L.head;
		for (int j = 1; j < i - 1; j++) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		if (p->next == nullptr) L.tail = p;  // 若插入在尾部，更新尾指针
	}

	L.len++;
	return OK;
}


Status ListDelete_L(LinkList& L, int i, ELemType& e) {
	if (i > L.len || i < 1)return ERROR;
	Link current, pre;
	pre = current = L.head;
	for (int j = 1; j <= i; j++) {
		pre = current;
		current = current->next;
	}
	e = current->data;
	pre->next = current->next;

	L.len--;
	return OK;
}
