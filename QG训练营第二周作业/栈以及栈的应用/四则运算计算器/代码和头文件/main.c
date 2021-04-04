#include "Calculator.h"
#include "Calculator.c"
#include <windows.h>

LinkStack s_num, s_opt;

void show();//展示操作列表
int Priority(char ch);//获取优先级
int judge_scanf();//规范输入

int main() {
    printf("该计算器仅支持含有整数，小数与加减乘除和括号的运算，不支持负数运算\n");
    if (!initLStack(&s_num) || !initLStack(&s_opt))//将数字栈和运算符栈进行初始化
    {
        printf("初始化失败！\n");
        return -1;
    }

    char opt[128] = { 0 }, sign = '!', q = '!';
    int i = 0, choice = 0,check = 1;//check作为判断表达式是否规范的标志
    double tmp = 0, num1 = 0,little = 1.0, num2 = 0, result = 0;

    do
    {
        check = 1;
        show();
        choice = judge_scanf();
        system("cls");
        for (int j = 0; j < sizeof(opt); j++)
        {
            opt[j] = '\0';
        }
        switch (choice)
        {
        case 1:
        {
            printf("请输入运算表达式：");
            scanf("%s", opt);
            while (opt[i] != '\0' || !isEmptyLStack(&s_opt))
            {
                if (opt[i] >= '0' && opt[i] <= '9')
                {
                    tmp = tmp * 10 + (double)(opt[i] - '0');
                    i++;
                    if ((opt[i] < '0' || opt[i] >'9') && opt[i] != '.')//判断是否为小数
                    {
                        pushLStack_num(&s_num, tmp);
                        tmp = 0;
                    }
                }
                else if (opt[i] == '.')
                {
                    i++;
                    while (opt[i] >= '0' && opt[i] <= '9')
                    {
                        little = little * 0.1;
                        tmp = tmp + (little * (double)(opt[i] - '0'));
                        i++;
                    }
                    pushLStack_num(&s_num, tmp);
                    tmp = 0;
                    little = 1.0;
                }
                else
                {
                    if (isEmptyLStack(&s_opt) && opt[i] != '\0')
                    {
                        pushLStack_opt(&s_opt, opt[i]);
                        i++;
                        continue;
                    }
                    else {
                        getTopLStack_opt(&s_opt, &sign);
                        if (Priority(sign) < Priority(opt[i]) || (sign == '(' && opt[i] != ')'))
                        {
                            pushLStack_opt(&s_opt, opt[i]);
                            i++;
                            continue;
                        }
                        if (sign == '(' && opt[i] == ')')
                        {
                            popLStack_opt(&s_opt, &q);
                            i++;
                            continue;
                        }
                        if (Priority(sign) >= Priority(opt[i]) || (opt[i] == ')' && sign != '(') || (opt[i] == '\0'
                            && !isEmptyLStack(&s_opt)))
                        {
                            popLStack_opt(&s_opt, &q);
                            if (returnLength(&s_num) < 2)
                            {
                                printf("请输入规范的表达式！\n");
                                check = 0;
                                break;
                            }
                            else {
                                switch (q)
                                {
                                    case '+':
                                    {
                                        popLStack_num(&s_num, &num1);
                                        popLStack_num(&s_num, &num2);
                                        pushLStack_num(&s_num, num2 + num1);
                                        break;
                                    }
                                    case '-':
                                    {
                                        popLStack_num(&s_num, &num1);
                                        popLStack_num(&s_num, &num2);
                                        pushLStack_num(&s_num, num2 - num1);
                                        break;
                                    }
                                    case '*':
                                    {
                                        popLStack_num(&s_num, &num1);
                                        popLStack_num(&s_num, &num2);
                                        pushLStack_num(&s_num, num2 * num1);
                                        break;
                                    }
                                    case '/':
                                    {
                                        popLStack_num(&s_num, &num1);
                                        popLStack_num(&s_num, &num2);
                                        pushLStack_num(&s_num, num2 / num1);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (check == 1) {
                popLStack_num(&s_num, &result);
                printf("计算结果为：%.2lf\n", result);
            }
            i = 0;
            break;
        }
        case 2:
        {
            destroyLStack(&s_num);
            destroyLStack(&s_opt);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-2)\n");
            break;
        }
        }
    } while (choice != 2);

}

void show() {
    printf("\n\n\n计算器\n\n");
    printf("1.进行计算\n");
    printf("2.退出\n");
    printf("\n请输入对应的数字(1-2)：");
}

int Priority(char ch)
{
    switch (ch)
    {
    case '(':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

int judge_scanf()  //防止用户输入不合法的数据
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if ((word[m] < '0' || word[m]>'9') && word[m] != '-')  //检验是否有乱输入其他字符
            {
                printf("你输入的不是整数，请重新输入：");
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
        if (word[m] == '-')
        {
            continue;
        }

        for (k = 0; k < j; k++) {
            arg *= 10;
        }
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    for (m = 0; m < strlen(word); m++)
    {
        if (word[m] == '-')
        {
            return -num / 10;
        }

    }
    return num;
}