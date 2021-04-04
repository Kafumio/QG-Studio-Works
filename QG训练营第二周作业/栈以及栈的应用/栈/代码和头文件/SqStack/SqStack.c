#include "SqStack.h"
#include <stdlib.h>

Status initStack(SqStack *s,int sizes){
    if (sizes > 0)
    {
        s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
        s->top = -1;
        s->size = sizes;
        return SUCCESS;
    }else{
        printf("您输入的容量有误，请输入一个正整数！\n");
    }
    return ERROR;
}

Status isEmptyStack(SqStack *s){
    if (s->top == -1)
    {
        return SUCCESS;
    }else{
        return ERROR;
    }
}

Status getTopStack(SqStack *s,ElemType *e){
    if (s->elem == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (!isEmptyStack(s))
    {
        *e = s->elem[s->top];
        return SUCCESS;
    }else{
        printf("栈为空！\n");
    }
    return ERROR;
}

Status clearStack(SqStack *s){
    if (s->elem == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (isEmptyStack(s))
    {
        printf("栈为空！\n");
        return ERROR;
    }
    s->top = -1;
    return SUCCESS;
}

Status destroyStack(SqStack *s){
    if (s->elem == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    free(s->elem);
    s->elem=NULL;
    s->top = -1;
    s->size = 0;
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length){
    *length = s->top + 1;
    return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){
    if (s->elem == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    int length;
    stackLength(s,&length);
    if (s->size > length)
    {
        s->top++;
        s->elem[s->top] = data;
        return SUCCESS;
    }
    printf("栈溢出！\n");
    return ERROR;
}

Status popStack(SqStack *s,ElemType *data){
    if (s->elem == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (!isEmptyStack(s))
    {
        *data = s->elem[s->top];
        s->top--;
        return SUCCESS;
    }
    printf("栈已空\n");
    return ERROR;
}