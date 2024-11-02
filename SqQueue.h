//循环队列
#pragma once

#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
#define MAXQSIZE 100
typedef int QElemType;

typedef struct {
	QElemType* base;//初始化的动态分配空间
	int front;//头指针，若队列不空，指向队列头元素
	int rear;//尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;

/// <summary>
/// 初始化
/// </summary>
/// <param name="Q"></param>
/// <returns>成功返回OK，失败返回OVERFLOW</returns>
Status InitQueue(SqQueue& Q);

/// <summary>
/// 求队列长度
/// </summary>
/// <param name="Q"></param>
/// <returns>队列长度</returns>
int QueueLength(SqQueue Q);

/// <summary>
/// 入队
/// </summary>
/// <param name="Q"></param>
/// <param name="e">新入队元素</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status EnQueue(SqQueue& Q, QElemType e);

/// <summary>
/// 出队
/// </summary>
/// <param name="Q"></param>
/// <param name="e">出队元素</param>
/// <returns>成功返回OK，失败返回ERROR</returns>
Status DeQueue(SqQueue& Q, QElemType& e);

