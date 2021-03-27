#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "linkedList.c"

//工具函数
void visit(ElemType e);//输出数据
void show();//选项展示
int judge_scanf();//判断输入数据是否合法
LinkedList getNode(LinkedList h,int n);//获取对应节点
LinkedList createNode();//创建一个节点

int main()
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