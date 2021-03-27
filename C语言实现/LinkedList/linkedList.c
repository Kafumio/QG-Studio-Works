#include "linkedList.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

//工具函数
void visit(ElemType e);//输出数据
void show();//选项展示
int judge_scanf();//判断输入数据是否合法
LinkedList getNode(LinkedList h,int n);//获取对应节点
LinkedList createNode();//创建一个节点

int main(void)
{
    int choice = 0, num = 0,a = 0;
    ElemType *e = &a,value = 0;
    LinkedList head = NULL;

    do
    {
        show();
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1://创建空链表
            {
                if(InitList(&head))
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
                DestroyList(&head);
                printf("链表销毁完成\n");
                break;
            }
            case 3://插入节点
            {
                if(head == NULL)
                {
                    printf("链表为空， 请先创建链表\n");
                }
                else
                {
                    printf("你想在第几个节点后插入新节点：");
                    scanf("%d", &num);
                    if(InsertList(getNode(head,num),createNode()))
                    {
                        printf("插入成功\n");
                    }
                    else
                    {
                        printf("插入失败\n");
                    }
                }
                break;
            }
            case 4://删除节点
            {
                printf("你想删除第几个节点之后的节点：");
                scanf("%d",&num);
                if(DeleteList(getNode(head,num),e))
                {
                    printf("删除成功,被删除的节点数据为%d\n",*e);
                }
                else
                {
                	printf("删除失败\n");
                }
                break;
            }
            case 5://遍历链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表不存在或者只存在一个空的头结点\n");
                }
                else
                {
                    TraverseList(head,visit);
                }
                break;
            }
            case 6://查找数据
            {
                printf("请输入你要查询的数据：");
                value = judge_scanf();
                if(SearchList(head, num))
                {
                    printf("该数存在\n");
                }
                else
                {
                    printf("该数不存在\n");
                }
                break;
            }
            case 7://反转链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空或者链表只含有两个结点\n");
                    printf("链表反转失败\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("链表反转成功\n");
                    }
                    else
                    {
                        printf("链表反转失败\n");
                    }

                }
                break;
            }
            case 8://判断链表是否成环
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("链表成环\n");
                    }
                    else
                    {
                        printf("链表没有成环\n");
                    }
                }
                break;
            }
            case 9://反转链表中的偶数结点
            {
                ReverseEvenList(&head);
                printf("操作成功！\n");
                break;
            }
            case 10://查找中间结点
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("这是空链表\n");
                }
                else
                {
                    FindMidNode(&head);
                }
                break;
            }
            case 11://退出程序
            {
                DestroyList(&head);
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-11)\n");
                break;
            }
        }
    } while (choice != 11);

    return 0;
}

void show(){
    printf("\n\n\n单链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.插入结点\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.查询数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.反转链表中的偶数结点与奇数节点\n");
    printf("10.查找中间节点\n");
    printf("11.退出\n");
    printf("\n请输入对应的数字(1-11)：");
}

void visit(ElemType e){
    printf("%d->",e);
}

int judge_scanf()  //防止用户输入不合法的数据
{
    int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // 将字符重新转换为数字
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

LinkedList getNode(LinkedList h,int n)//获取需要用到的节点
{
    if(n<1) return NULL;
    LinkedList p = h;

    for(int i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)
            return NULL;
    }

    return p;
}

LinkedList createNode()//创建一个新节点
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("请输入你要插入的数据：");
    q->data = judge_scanf();
    return q;
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L){
    LinkedList list;
    list = (LinkedList)malloc(sizeof(LNode));
    if (list == NULL)
    {
        printf("内存分配失败！");
        return ERROR;
    }
    list->next = NULL;
    *L = list;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L){
    LinkedList temp;
    while (*L != NULL)
    {
        temp = *L;
        *L = (*L) -> next;
        free(temp);
    }
    
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q){
    if (!p)
    {
        printf("指定节点不存在！");
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e){
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
    LNode *t = p->next;
    *e = t->data;
    p->next = t->next;
    free(t);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)){
    L = L->next;
    while (L)
    {
        visit(L->data);
        L=L->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e){
    while (L)
    {
        if(L->data == e){
            return SUCCESS;
        }
        L = L->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L){
    if(!(*L)) return ERROR;
    LinkedList p1,p2,p3;
    p1 = *L;
    p2 = p3 = p1->next;
    p1->next = NULL;
    while(p3){
        p3 = p3->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    *L = p1;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L){
    if(!L) return ERROR;
    LinkedList p1 = L->next, p2 = L->next->next;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 == p2){
            return SUCCESS;  
        }
        p2 = p2->next->next;
        p1 = p1->next;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L){
    LinkedList p1,p2,h,t;
    int n = 0;
    h=p1 = *L;
    while(p1->next)
    {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        if(++n == 1){
            h = p2;
        }else {
            t->next = p2;
        }
        t = p1;
        p1 = p1->next;
        if(!p1)break;
    }
    return h;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L){
    LinkedList p1,p2;
    p1 = p2 = *L;

    while (p2)
    {
        p2 = p2->next->next;
        p1 = p1->next;
        if (p2->next == NULL) {
        printf("中间节点的数据为%d\n",p1->data);
        break;
        }
        if (p2->next->next == NULL) {
            printf("中间节点数据为%d-%d\n",p1->data,p1->next->data);
            break;
        }
    }
    return p1;
}

