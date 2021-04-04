#ifndef CALCULATOR_H_INCLUDE
#define CALCULATOR_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

typedef enum Status 
{
	ERROR,SUCCESS
}Status;

typedef  struct StackNode
{
	double data;
    char opt;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack_num(LinkStack *s,double *e);//得到栈顶元素
Status getTopLStack_opt(LinkStack *s,char *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status pushLStack_num(LinkStack *s,double data);//入数字栈
Status pushLStack_opt(LinkStack *s,char opt);//入运算符栈
Status popLStack_num(LinkStack *s,double *data);//出数字栈
Status popLStack_opt(LinkStack *s,char *data);//出运算符栈
int returnLength(LinkStack* s);//返回栈长度

#endif 
