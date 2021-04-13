#include "LQueue.h"
#include "LQueue.c"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LQueue Q;

void show();//展示操作列表
int option_scanf();
int judge_scanf();

int main(){
    int choice = 0,flag = 0,value1;
    char value2;
    double value3;
    void* e;
    do
    {
        show();
        choice = judge_scanf();
        system("cls");
        switch (choice)
        {
            case 1:
            {
                InitLQueue(&Q);
                break;
            }
            case 2:
            {
                GetHeadLQueue(&Q,e);
                break;
            }
            case 3:
            {
                ClearLQueue(&Q);
                break;
            }
            case 4:
            {
                DestoryLQueue(&Q);
                break;
            }
            case 5:
            {
                int flag = option_scanf();
                if (flag == 1)
                {
                    value1 = judge_scanf();
                    Q.length = sizeof(int);
                    if (EnLQueue(&Q,&value1))
                    {
                        printf("入队成功！\n");
                    }
                }
                if (flag == 2)
                {
                    value2 = getchar();
                    scanf("%c",&value2);
                    Q.length = sizeof(char);
                    if (EnLQueue(&Q,&value2))
                    {
                        printf("入队成功！\n");
                    }
                }
                if (flag == 3)
                {
                    scanf("%lf",&value3);
                    Q.length = sizeof(double);
                    if (EnLQueue(&Q,&value3))
                    {
                        printf("入队成功！\n");
                    }
                }
                break;                                
            }
            case 6:
            {
                if (DeLQueue(&Q))
                {
                    printf("出队成功！\n");
                }
                break;
            }
            case 7:
            {
                int length = LengthLQueue(&Q);
                printf("现队列长度为：%d",length);
                break;
            }
            case 8:
            {
                if (TraverseLQueue(&Q,LPrint))
                {
                    printf("\n");
                    printf("遍历成功！\n");
                }
                break;
            }
            case 9:
            {
                DestoryLQueue(&Q);
                break;
            }
            default:
            {
                printf("请重新输入数字!(1-9)\n");
                break;
            }
        }
    } while (choice != 9);
    return 0;
}

//展示操作列表
void show(){
    printf("\n\n\n链队列ADT\n\n");
    printf("1.初始化队列\n");
    printf("2.查看队头元素\n");
    printf("3.清空队列元素\n");
    printf("4.销毁队列\n");
    printf("5.入队\n");
    printf("6.出队\n");
    printf("7.查看队列长度\n");
    printf("8.遍历队列\n");
    printf("9.退出\n");
    printf("\n请输入对应的数字(1-9)：");
}

int option_scanf(){

    int option = 0;
    printf("请选择你要输入的数据的类型(1:整数 2:字母 3:小数)：");
    while (1)
    {
        scanf("%d",&option);
        system("cls");
        if(option == 1){
            printf("请输入你要输入的整数：");
            type = 'i';
            break;
        }
        if (option == 2)
        {
            printf("请输入你要输入的字母：");
            type = 'c';
            break;
        }
        if (option == 3)
        {
            printf("请输入你要输入的小数：");
            type = 'f';
            break;
        }
        printf("请正确输入(1-3)的选项:");
    }
    return option;
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