#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


//工具函数
void visit(ElemType e);//输出数据
void show();//选项展示
int judge_scanf();//判断输入数据是否合法
DuLinkedList getNode(DuLinkedList h, int n);//获取对应节点
DuLinkedList createNode();//创建一个节点

int main() {
    int choice = 0, num = 0, a = 0;
    ElemType* e = &a;
    DuLinkedList head = NULL;

    do {
        show();
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1://创建空链表
        {
            if (InitList_DuL(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://销毁链表
        {
            DestroyList_DuL(&head);
            printf("链表销毁成功\n");
            break;
        }
        case 3://在某个节点前插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想在第几个节点前插入：");
                scanf("%d", &num);
                if (InsertBeforeList_DuL(getNode(head, num), createNode()))
                {
                    printf("插入成功！");
                }
                else {
                    printf("插入失败：指定节点不存在");
                }
            }
            break;
        }
        case 4://在某个节点后插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想在第几个节点后插入：");
                scanf("%d", &num);
                if (InsertAfterList_DuL(getNode(head, num), createNode()))
                {
                    printf("插入成功！");
                }
                else {
                    printf("插入失败：指定节点不存在");
                }
            }
            break;
        }
        case 5://删除节点
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想删除第几个节点之后的节点：");
                scanf("%d", &num);
                if (DeleteList_DuL(getNode(head, num), e))
                {
                    printf("删除成功！被删除的节点数据为：%d\n", *e);
                }
                else {
                    printf("删除失败！\n");
                }
            }
            break;
        }
        case 6://遍历链表
        {
            TraverseList_DuL(head, visit);
            break;
        }
        case 7://退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字!(1-7)\n");
            break;
        }
        }
    } while (choice != 7);
    return 0;
}

void show(void)
{
    printf("\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.在某个节点前插入新节点\n");
    printf("4.在某个节点后插入新节点\n");
    printf("5.删除数据\n");
    printf("6.遍历链表\n");
    printf("7.退出\n");
    printf("\n请输入对应的数字(1-7)：");
}

int judge_scanf()  //防止用户输入不合法的数据
{
    int len, num = 0, arg = 1;
    char word[10] = {0};
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word ,10);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // 将字符重新转换为数字
    {
        for (k = 0; k < j; k++)
        {
            arg *= 10;
        }
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}

//找到需要用到的节点
DuLinkedList getNode(DuLinkedList h, int n)
{
    if (n < 1) return NULL;

    DuLinkedList p = h;

    for (int i = 1; i < n; i++)
    {
        if ((i < n - 1 && p->next == NULL) || p->next == NULL)
            return NULL;
        p = p->next;
    }
    return p;
}

//创建一个节点
DuLinkedList createNode()
{
    DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
    if (q == NULL) {
        return NULL;
    }
    else {
        printf("请输入你要插入的数据：");
        q->data = judge_scanf();
        q->next = q->prior = NULL;
        return q;
    }

}

void visit(ElemType e)
{
    printf("%d->", e);
}

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