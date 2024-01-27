#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,ElemType len)
{
    ST.TableLen=len;
    int i;
    ST.elem=(ElemType *) malloc(sizeof (ElemType)*ST.TableLen);
    srand(time(NULL));
    for(i=0;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;
    }
}
void ST_Print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
    {
        printf("%3d",ST.elem[i]);
    }
}
int BinarySearch(SSTable ST,ElemType key)
{
    int low=0;
    int high=ST.TableLen-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(ST.elem[mid]==key){
            return mid+1;
        }
        else if(ST.elem[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return 0;
}

//函数名存的是函数的入口指针
//qsort规定left指向的值>right指向的值返回正值，相等返回0，小于返回负值，指向任意两个元素。
int compare(const void *left,const void *right)
{
    //从小到大，左边小于右边
    return *(int*)left-*(int*)right;
}




int main()
{
    SSTable ST;
    ST_Init(ST,10);
    qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);
    ST_Print(ST);
    printf("\n");
    ElemType key;
    printf("输入你要查找的数：\n");
    fflush(stdout);
    scanf("%d",&key);
    int pos= BinarySearch(ST,key);
    if(pos){
        printf("它在第%d位。",pos);
    }
    else{
        printf("查找失败");
    }

    return 0;
}