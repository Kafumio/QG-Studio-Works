#include "LinkStack.h"
#include <stdlib.h>

Status initLStack(LinkStack *s){
    s->top = (StackNode*)malloc(sizeof(StackNode));
    s->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){
    if (s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }    
    if (!isEmptyLStack(s))
    {
        *e = s->top->data;
        return SUCCESS;
    }else{
        printf("栈为空！\n");
    }
    return ERROR;
}

Status clearLStack(LinkStack *s){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (isEmptyLStack(s))
    {
        printf("栈为空！\n");
        return ERROR;
    }
    s->count = 0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    free(s->top);
    s->top = NULL;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){
    *length = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (!isEmptyLStack(s))
    {
        LinkStackPtr p = s->top;
        *data = s->top->data;
        s->top = s->top->next;
        free(p);
        s->count--;
        return SUCCESS;
    }
    printf("栈已空\n");
    return ERROR;
}