#include "qgsort.h"
#include "qgsort.c"
#include <windows.h>

void show();
void testtime(int choice);
void readdata(int num,int *a,FILE *fp);

int main(){
    int choice = 0;
    do{
        show();
        scanf("%d",&choice);
        printf("\n\n");
        testtime(choice);
    } while (choice != 3);
    return 0;
}

void show(){
    printf("\n\n\n\t*请输入对应编号*\t");
    printf("\n\n-------1.100 * 100k数据测试--------\n");
    printf("-------2.自定义数据测试--------\n");
    printf("-------3.退出--------\n\n");
    printf("注：数字为0~1000的随机数，数组定长为100\n\n\n");
    printf("请输入你的选择：");
}

void readdata(int num,int *a,FILE *fp){
    fp = fopen("testdata.txt","r");
    if (fp == NULL)
    {
        printf("file is not exsits!\n");
        exit(0);
    }
    for (int j = 0; j < num; j++)
    {
        fscanf(fp,"%d ",&a[j]);
    }
    fclose(fp);
}

void testtime(int choice){
    int num = 100;
    int a[100],count = 100000;
    assert(choice);
    if (choice == 1)
    {
        printf("100 * 100k次排序花费时间：\n");
    }
    if (choice == 2){
        printf("请输入你要测试的次数：");
        scanf("%d",&count);
        printf("自定义数据测试花费时间：\n");         
    }
    if(choice == 3){
        exit(0);
    }
    if (choice < 1 || choice > 3)
    {
        printf("请输入正确的选项");
        return;
    }
    FILE *fp;
    int time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        insertSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("插入排序用时：%dms\n",time);
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        MergeSort(a,0,num-1,a);
        int end = GetTickCount();
        time += end - start;
    }
    printf("归并排序用时：%dms\n",time);
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        QuickSort_Recursion(a,0,num-1);
        int end = GetTickCount();
        time += end - start;
    }
    printf("快速排序(递归版)用时：%dms\n",time);
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        QuickSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("快速排序(非递归版)用时：%dms\n",time);
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        Partition(a,0,num-1);
        int end = GetTickCount();
        time += end - start;
    }
    printf("快速排序(枢轴存放)用时：%dms\n",time); 
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        CountSort(a,num,GetMax(a,100));
        int end = GetTickCount();
        time += end - start;
    }
    printf("计数排序用时：%dms\n",time);
    time = 0;
    for (int i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        RadixCountSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("基数计数排序用时：%dms\n",time);            
                       
}