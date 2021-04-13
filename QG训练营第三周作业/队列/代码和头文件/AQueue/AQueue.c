#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitAQueue(AQueue *Q){
	int i;
	for (i = 0; i < MAXQUEUE; i++)
    {
        Q->data[i] = (void *)malloc(MAXQUEUE);
    }
	Q->front = 0;
	Q->rear  = 0;
    printf("初始化队列成功！\n");
}

void DestoryAQueue(AQueue *Q) {
	int i;
	for (i = 0; i < MAXQUEUE; i++)
    {
        free(Q->data[i]);
    }
    printf("销毁成功！");
	return;
}

Status IsFullAQueue(const AQueue *Q) {
	return (Q->front == (Q->rear + 1) % MAXQUEUE? TRUE: FALSE);
}

Status IsEmptyAQueue(const AQueue *Q) {
	return (Q->front == Q->rear?TRUE: FALSE);
}

Status GetHeadAQueue(AQueue *Q, void *e) {
	if (IsEmptyAQueue(Q))
    {
        printf("队列为空，请先将元素入队！\n");
        return FALSE;
    }
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
    type = datatype[i];
    printf("队头元素为：");
    if(type == 'i'){
        Q->length = sizeof(int);
        memcpy(e, Q->data[i], Q->length);
        printf("%d",*(int*)e);
    }
    if(type == 'c'){
        Q->length = sizeof(char);
        memcpy(e, Q->data[i], Q->length);
        printf("%c",*(char*)e);
    }
    if(type == 'f'){
        Q->length = sizeof(double);
        memcpy(e, Q->data[i], Q->length);
        printf("%lf",*(double*)e);
    }
	return TRUE;
}

int LengthAQueue(AQueue *Q) {
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE; 
}

Status EnAQueue(AQueue *Q, void *data) {
	if (IsFullAQueue(Q)) 
    {
        printf("队列已满，入队失败！\n");
        return FALSE;
    }
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->length);
    datatype[Q->rear] = type;
	return TRUE;
}

Status DeAQueue(AQueue *Q) {
	if (Q->front == Q->rear)
    {
        return FALSE;
    }
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
    {
        printf("队列已空，无法清空！\n");
        return;
    }
	Q->front = 0;
	Q->rear = 0;
	return;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)) { 
	if (Q->front == Q->rear)
    {
        return FALSE;
    }	
	int i = (Q->front + 1) % MAXQUEUE;
	while (i <= (MAXQUEUE + Q->rear) % MAXQUEUE ) {
        type = datatype[i];
		foo(Q->data[i]);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

void APrint(void *q) {
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