#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

#define testdata1 10000
#define testdata2 50000
#define testdata3 200000
#define testdata4 100000
#define Max 1000

void show();
void optionWrite(int c,FILE *fp);
int rand_number();

int main(){
    int choice;
    srand((int)time(NULL));
    FILE *fp;
    show();
    scanf("%d",&choice);
    optionWrite(choice,fp);
    return 0;
}

void show(){
    printf("\t*请输入对应编号生成测试数据*\t");
    printf("\n\n--------1.生成%d个0~%d的随机数--------\n",testdata1,Max);
    printf("--------2.生成%d个0~%d的随机数--------\n",testdata2,Max);
    printf("--------3.生成%d个0~%d的随机数--------\n",testdata3,Max);    
    printf("请输入你的选择：");
}

void optionWrite(int c,FILE *fp){
    assert(c);
    int num;
    switch (c)
    {
        case 1:
        {
            fp = fopen("testdata.txt","w");
            for(int i = 1;i <= testdata1;i++)
            {
                num = rand_number();//产生随机数 
                fprintf(fp,"%d ",num);//输出到文件 
            }
            fclose(fp);
            printf("成功生成%d个0~%d的随机数，已保存至txt，请查看",testdata1,Max);  
            break;
        }
        case 2:
        {
            fp = fopen("testdata.txt","w");
            for(int i = 1;i <= testdata2;i++)
            {
                num = rand_number();//产生随机数 
                fprintf(fp,"%d ",num);//输出到文件 
            }
            fclose(fp);
            printf("成功生成%d个0~%d的随机数，已保存至txt，请查看",testdata2,Max);  
            break;
        }
        case 3:
        {
            fp = fopen("testdata.txt","w");
            for(int i = 1;i <= testdata3;i++)
            {
                num = rand_number();//产生随机数 
                fprintf(fp,"%d ",num);//输出到文件 
            }
            fclose(fp);
            printf("成功生成%d个0~%d的随机数，已保存至txt，请查看",testdata3,Max);  
            break;
        }                
        default:
        {
            printf("你的选择错误！\n");
            break;
        }    
    }
}

int rand_number()
{
	int num;
	num = rand() % Max;
	return num;
}