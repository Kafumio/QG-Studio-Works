#include "duLinkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList Dulist = (DuLinkedList)malloc(sizeof(DuLNode));
    if (Dulist == NULL)
    {
        printf("内存分配失败！\n");
        return ERROR;
    }
    else {
        Dulist->next = NULL;
        Dulist->prior = NULL;
        *L = Dulist;
        return SUCCESS;
    }
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
    if (!p) {
        return ERROR;
    }
    if (p->prior) {
        q->prior = p->prior;
        p->prior->next = q;
    }
    q->next = p;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
    if (!p) {
        return ERROR;
    }
    if (p->next)
    {
        q->next = p->next;
        p->next->prior = q;
    }
    q->prior = p;
    p->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (!p)
    {
        printf("指定节点不存在！");
        return ERROR;
    }
    if (!(p->next))
    {
        printf("该节点已是最后一个节点！");
        return ERROR;
    }
    DuLNode* t = p->next;
    *e = t->data;
    p->next = t->next;
    t->next->prior = p;
    free(t);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    L = L->next;
    while (L) {
        visit(L->data);
        L = L->next;
    }
}