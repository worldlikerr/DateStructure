#include"SqStack.h"
#include<iostream>
using namespace std;

int main() {
	SqStack S;
	InitStack(S);
	cout << (StackEmpty(S) ? "栈空" : "非空");
	cout << endl;

	for (int i = 0; i < 5; i++) {
		Push(S, i);
		SELemType e;
		GetTop(S, e);
		cout << e << endl;
	}

	for (int i = 0; i < 5; i++) {
		SELemType e;
		Pop(S, e);
		cout << e << endl;
	}
}