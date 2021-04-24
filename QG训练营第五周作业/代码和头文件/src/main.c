#include "binary_sort_tree.h"
#include "binary_sort_tree.c"
#include <windows.h>

BinarySortTree bst;

void show();
int judge_scanf();  //防止用户输入不合法的数据

int main() {
    int choice = 0;
    ElemType value = 0;
    do
    {
        show();
        choice = judge_scanf();
        system("cls");
        switch (choice)
        {
            case 1:
            {
                if(BST_init(&bst)){
                    printf("树初始化成功！\n");
                }
                break;
            }
            case 2:
            {
                printf("请输入一个整数：");
                value = judge_scanf();
                if (BST_insert(&bst,value))
                {
                    printf("插入成功！\n");
                }else{
                    printf("插入失败！\n");
                }
                break;
            }
            case 3:
            {
                printf("请输入一个整数：");
                value = judge_scanf();
                if (BST_delete(&bst,value))
                {
                    printf("删除成功！\n");
                }else{
                    printf("删除失败！\n");
                }
                break;
            }
            case 4:
            {
                printf("请输入一个整数：");
                value = judge_scanf();
                if (BST_search(&bst,value))
                {
                    printf("树中确实存在此元素\n");
                }
                break;
            }
            case 5:
            {
                printf("前序遍历(非递归):");
                if (!BST_preorderI(&bst,visit))
                {
                    printf("遍历失败");
                }
                break;
            }
            case 6:
            {
                printf("前序遍历(递归):");
                if (!BST_preorderR(&bst,visit))
                {
                    printf("遍历失败");
                }
                break;
            }
            case 7:
            {
                printf("中序遍历(非递归):");
                if (!BST_inorderI(&bst,visit))
                {
                    printf("遍历失败！\n");
                }
                break;
            }
            case 8:
            {
                printf("中序遍历(递归):");
                if (!BST_inorderR(&bst,visit))
                {
                    printf("遍历失败！\n");
                }
                break;
            }
            case 9:
            {
                printf("后序遍历(非递归):");
                if (!BST_postorderI(&bst,visit))
                {
                    printf("遍历失败！\n");
                }
                break;
            }
            case 10:
            {
                printf("后序遍历(递归):");
                if (!BST_postorderR(&bst,visit))
                {
                    printf("遍历失败！\n");
                }
                break;
            }
            case 11:
            {
                printf("层序遍历:");
                if (!BST_levelOrder(&bst,visit))
                {
                    printf("遍历失败！\n");
                }
                break;
            }
            case 12:
            {
                //free((&bst)->root);
                break;
            }                                                                          
            default:
            {
                printf("请重新输入数字!(1-12)\n");
                break;
            }
        }
    } while (choice != 12);
    return 0;
}

//展示操作列表
void show(){
    printf("\n\n\n二叉查找树ADT\n\n");
    printf("1.初始化树\n");
    printf("2.插入树中元素\n");
    printf("3.删除树中元素\n");
    printf("4.搜索树中是否存在对应元素\n");
    printf("5.前序遍历(非递归)\n");
    printf("6.前序遍历(递归)\n");
    printf("7.中序遍历(非递归)\n");
    printf("8.中序遍历(递归)\n");
    printf("9.后序遍历(非递归)\n");
    printf("10.后序遍历(递归)\n");
    printf("11.层序遍历\n");
    printf("12.退出\n");
    printf("\n请输入对应的数字(1-12)：");
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
            if((word[m]<'0' || word[m]>'9') && word[m] != '-')  //检验是否有乱输入其他字符
            {
                printf("你输入的不是整数，请重新输入：");
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
        if (word[m] == '-')
        {
            continue;
        }
        
        for(k=0;k<j;k++){
            arg *= 10;
        }
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;  
    }
    for (m = 0; m < strlen(word); m++)
    {
        if (word[m] == '-')
        {
            return -num/10;
        }
        
    }
    return num;
}