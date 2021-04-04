#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "SqStack.c"

void show();
int judge_scanf();  //防止用户输入不合法的数据

SqStack sq;

int main(){
    int choice = 0;
    ElemType data = 0;

    do
    {
        show();
        choice = judge_scanf();
        system("cls");
        switch (choice)
        {
            case 1:
            {
                printf("请输入你要设置的栈容量：");
                int sizes = judge_scanf();
                while (1){
                    if (initStack(&sq,sizes))
                    {
                        printf("栈初始化成功！\n");
                        break;
                    }else{
                        printf("栈初始化失败！\n");
                    }
                    printf("请重新输入你要设置的栈容量：");
                    sizes = judge_scanf();
                    system("cls");
                }
                break;
            }
            case 2:
            {
                if (getTopStack(&sq,&data))
                {
                    printf("栈顶元素是：%d",data);
                }else{
                    printf("获取栈顶元素失败！\n");
                }
                break;
            }
            case 3:
            {
                if (clearStack(&sq))
                {
                    printf("栈元素已全部清除！\n");
                }else{
                    printf("栈元素清除失败！\n");
                }
                break;
            }
            case 4:
            {
                if (destroyStack(&sq))
                {
                    printf("栈已被销毁！\n");
                }else{
                    printf("栈元素销毁失败！\n");
                }
                break;
            }
            case 5:
            {
                printf("请输入一个整数数据：");
                data = judge_scanf();
                if (pushStack(&sq,data))
                {
                    printf("入栈成功！\n");
                }else{
                    printf("入栈失败！\n");
                }
                break;
            }
            case 6:
            {
                if (popStack(&sq,&data))
                {
                    printf("出栈的元素为：%d\n",data);
                }else{
                    printf("出栈失败！\n");
                }
                break;
            }      
            case 7:
            {
                destroyStack(&sq);
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

void show(){
    printf("\n\n\n顺序栈ADT\n\n");
    printf("1.初始化栈\n");
    printf("2.获得栈顶元素\n");
    printf("3.清空栈中元素\n");
    printf("4.销毁栈\n");
    printf("5.入栈\n");
    printf("6.出栈\n");
    printf("7.退出\n");
    printf("\n请输入对应的数字(1-7)：");
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