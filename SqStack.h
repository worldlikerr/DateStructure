#pragma once

#define OK 1
#define ERROR 0
typedef int SELemType;
typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	SELemType* base;
	SELemType* top;
	int stacksize;
}SqStack;

/// <summary>///创建 /// </summary>/// <param name="S">栈名</param>/// <returns>成功返回OK失败返回ERROR</returns>
Status InitStack(SqStack& S);

/// <summary>///判断栈是否为空 /// </summary>/// <param name="S">栈名</param>/// <returns>栈空返回ERROR非空返回OK</returns>
Status StackEmpty(SqStack S);

/// <summary>///取顶 /// </summary>/// <param name="S">栈名</param>/// <param name="e">所得到的栈顶元素值</param>/// <returns>成功返回OK失败返回ERROR</returns>
Status GetTop(SqStack S, SELemType& e);

/// <summary>///压入 /// </summary>/// <param name="S">栈名</param>/// <param name="e">所插入的元素值</param>/// <returns>成功返回OK失败返回ERROR</returns>
Status Push(SqStack& S, SELemType e);

/// <summary>///弹出 /// </summary>/// <param name="S">栈名</param>/// <param name="e">弹出的元素值</param>/// <returns>成功返回OK失败返回ERROR</returns>
Status Pop(SqStack& S, SELemType& e);