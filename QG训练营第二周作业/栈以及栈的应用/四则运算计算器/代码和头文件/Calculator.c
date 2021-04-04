#include "Calculator.h"

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

int returnLength(LinkStack* s) {
    int length = s->count;
    return length;
}

Status destroyLStack(LinkStack *s){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    free(s);
    return SUCCESS;
}

Status getTopLStack_num(LinkStack *s,double *e){
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

Status getTopLStack_opt(LinkStack *s,char *e){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }    
    if (!isEmptyLStack(s))
    {
        *e = s->top->opt;
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

Status pushLStack_num(LinkStack *s,double data){
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

Status pushLStack_opt(LinkStack *s,char opt){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->opt = opt;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

Status popLStack_num(LinkStack *s,double *data){
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

Status popLStack_opt(LinkStack *s,char* opt){
    if (s->top == NULL || s == NULL)
    {
        printf("请先初始化栈！\n");
        return ERROR;
    }
    if (!isEmptyLStack(s))
    {
        LinkStackPtr p = s->top;
        *opt = s->top->opt;
        s->top = s->top->next;
        free(p);
        s->count--;
        return SUCCESS;
    }
    printf("栈已空\n");
    return ERROR;
}