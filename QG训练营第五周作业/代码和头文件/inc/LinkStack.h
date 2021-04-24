#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SUCCESS 1

typedef  struct StackNode
{
	NodePtr root;
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
int pushLStack(LinkStack *s,NodePtr n);//入栈
Node* popLStack(LinkStack *s);//出栈


#endif 
