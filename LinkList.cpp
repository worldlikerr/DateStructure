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

		pre->next = temp;
		temp->next = L.tail;

		pre = temp;
		L.len++;
	}
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
	Link current = L.head->next;
	if (!current) return ERROR;
	for (int i = 1; i <= L.len; i++) {
		if (visit(current->data) == ERROR) return ERROR;
		current = current->next;
	}
	return OK;
}

Status ListInsert_L(LinkList& L, int i, ELemType e) {
	if (i > L.len + 1 || i < 1)return ERROR;
	Link current, pre;
	pre = current = L.head;
	for (int j = 1; j <= i; j++) {
		pre = current;
		current = current->next;
	}
	Link p;
	if (!MakeNode(p, e))return ERROR;
	pre->next = p;
	p->next = current;
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
