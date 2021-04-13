#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fro = 0;
int rea = 0;

void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL)
    {
        printf("队列初始化失败！\n");
        return;
    }
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
    fro = rea = 0;
    printf("队列初始化成功！\n");
	return;
}

void DestoryLQueue(LQueue *Q) {
	if (!IsEmptyLQueue(Q))
    { 
        ClearLQueue(Q);
    }
	free(Q->front);
	free(Q->rear);
    printf("销毁成功！\n");
}

Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}

Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
    {
        printf("队列为空，请先将元素入队\n");
        return FALSE;
    }
    int i = fro + 1;
    type = datatype[i];
    if (type == 'i')
    {
        Q->length = sizeof(int);
        memcpy(e, Q->front->next->data, Q->length);//在头结点下一个节点指向的位置赋予字节数 
        printf("队头元素为：%d",*(int*)e);
    }
    if(type == 'c')
    {
        Q->length = sizeof(char);
        memcpy(e, Q->front->next->data, Q->length);//在头结点下一个节点指向的位置赋予字节数
        printf("队头元素为：%c",*(char*)e); 
    }
    if (type == 'f')
    {
        Q->length = sizeof(double);
        memcpy(e, Q->front->next->data, Q->length);//在头结点下一个节点指向的位置赋予字节数
        printf("队头元素为：%lf",*(double*)e); 
    } 
	return TRUE;	
}

int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
    {
        p = p->next; 
    }
	return length;
}

Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (IsEmptyLQueue(Q) && (Q->front == NULL || Q->rear == NULL))
    {
        printf("队列未初始化，请先初始化队列！\n");
        return FALSE;
    }
	p->data = (void *)malloc(Q->length);
	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
    rea ++;
    datatype[rea] = type;
	return TRUE;
}

Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
    {
        printf("队列为空，请先将元素入队\n");
        return FALSE;
    }
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->front->next == NULL) 
    {
        Q->rear = Q->front;
    } 
	free(p);
    fro++;
	return TRUE;
}

void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
    {
        printf("队列已空，清空失败！\n");
        return;
    }
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
    fro = rea = 0;
	return;
}	

//foo利用Lprint打印函数 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
	if (IsEmptyLQueue(Q))
    {
        printf("队列为空，请先将元素入队\n");
        return FALSE;
    }
	Node* p = (void *)malloc(Q->length); 
	p = Q->front->next; 
	int i = fro + 1;
	while (p != NULL) {
        type = datatype[i];
		foo(p->data);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}

void LPrint(void *q) {
	if (type == 'f')
    {
        printf("%lf", *(double *)q);
    }
	if (type == 'c')
    {
        printf("%c", *(char *)q);
    }
	if (type == 'i')
    {
        printf("%d", *(int *)q);
    }
	printf("-<");
}