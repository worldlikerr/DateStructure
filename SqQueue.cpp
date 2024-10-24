#include"SqQueue.h"
#include<cstdlib>

Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue& Q, QElemType e) {
	if (QueueLength(Q) == MAXQSIZE)return ERROR;
	Q.base[Q.rear++] = e;
	Q.rear %= MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front++];
	Q.front %= MAXQSIZE;
	return OK;
}