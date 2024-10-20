#include"SqStack.h"
#include<iostream>
#include<cstring>
using namespace std;

Status InitStack(SqStack& S) {
	S.base = new SELemType[STACK_INIT_SIZE];
	if (!S.base)return ERROR;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S) {
	if (S.base != S.top)return ERROR;
	return OK;
}

Status GetTop(SqStack S, SELemType& e) {
	if (StackEmpty(S))return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack& S, SELemType e) {
	if (S.top - S.base >= S.stacksize) {
		SELemType* newbase = new SELemType[S.stacksize + STACKINCREMENT];
		if (!newbase)return ERROR;
		memcpy(newbase, S.base, S.stacksize * sizeof(SELemType));
		free(S.base);
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SELemType& e) {
	if (StackEmpty(S))return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}








