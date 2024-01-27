#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
    ElemType* elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len+1;//0号单元存放哨兵
    ST.elem=(ElemType*)malloc(ST.TableLen*sizeof(ElemType));
    int i;
    srand(time(NULL));
    for(i=1;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;//随机生成100以内的数
    }
}
void ST_Print(SSTable ST) {
    int i;
    for (i = 1; i < ST.TableLen; i++) {
        printf("%3d ", ST.elem[i]);
    }
    printf("\n");
}
int Search_Seq(SSTable ST,ElemType key)
{
    ST.elem[0]=key;//要查找的放在哨兵位置
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;--i);
    return i;
}


int main()
{
    SSTable ST;
    ElemType key;
    int pos;
    ST_Init(ST,10);
    ST_Print(ST);
    printf("\n");
    printf("input the key you want search:\n");
    fflush(stdout);
    scanf("%d",&key);
    pos=Search_Seq(ST,key);
    if(pos!=0)
    {
        printf("it's the %d num",pos);
    }
    else
    {
        printf("not found");
    }
    return 0;
}
