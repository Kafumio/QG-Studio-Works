#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SUCCESS 1;
typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
int initLStack(LinkStack *s);//初始化栈
int isEmptyLStack(LinkStack *s);//判断栈是否为空
int getTopLStack(LinkStack *s);//得到栈顶元素
int pushLStack(LinkStack *s,ElemType data);//入栈
int popLStack(LinkStack *s);//出栈
int destroyLStack(LinkStack *s);//销毁栈


#endif 
