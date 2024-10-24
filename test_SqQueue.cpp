#include"SqQueue.h"
#include<iostream>
using namespace std;
int main() {
	SqQueue Q;
	InitQueue(Q);
	cout << QueueLength(Q) << endl;

	for (int i = 0; i < 5; i++)EnQueue(Q, i);
	cout << QueueLength(Q) << endl;


	for (int i = 0; i < 5; i++) {
		QElemType e;
		DeQueue(Q, e);
		cout << e << " ";
	}
}