#include "LinkStack.h"

int initLStack(LinkStack *s){
    s->top = (StackNode*)malloc(sizeof(StackNode));
    s->count = 0;
    return SUCCESS;
}

int isEmptyLStack(LinkStack *s){
    if (s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

int getTopLStack(LinkStack *s){
    int e;
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }    
    if (!isEmptyLStack(s))
    {
        e = s->top->data;
        return e;
    }else{
        printf("栈为空！\n");
    }
    return ERROR;
}

int pushLStack(LinkStack *s,ElemType data){
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
int popLStack(LinkStack *s){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (!isEmptyLStack(s))
    {
        LinkStackPtr p = s->top;
        int data = s->top->data;
        s->top = s->top->next;
        free(p);
        s->count--;
        return data;
    }
    printf("栈已空\n");
    return ERROR;
}

int destroyLStack(LinkStack *s){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    free(s->top);
    s->top = NULL;
    return SUCCESS;
}