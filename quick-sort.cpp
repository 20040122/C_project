#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;
void Init(SSTable &ST,int len){
    ST.TableLen=len;
    ST.elem=(ElemType *) malloc(sizeof (ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));
    for(i=0;i<ST.TableLen;i++){
        ST.elem[i]=rand()%100;
    }
}
void Pint(SSTable ST){
    for(int i=0;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

int partition(ElemType *elem,int low,int high){
    ElemType pivot=elem[low];//分隔值
    while(low<high){
        while(low<high&&elem[high]>=pivot)
            --high;
        elem[low]=elem[high];
        while(low<high&&elem[low]<=pivot)
            ++low;
        elem[high]=elem[low];
    }
    elem[low]=pivot;//将分隔值填入
    return low;
}

//优先写内层
void Quick_Sort(ElemType *elem,int low,int high){
    if(low<high) {
        int pivot_pos = partition(elem, low, high);//存储分隔值位置
        Quick_Sort(elem, low, pivot_pos - 1);
        Quick_Sort(elem, pivot_pos + 1, high);
    }
}

int main(){
    SSTable ST;
    Init(ST,10);
    Pint(ST);
    Quick_Sort(ST.elem,0,9);
    Pint(ST);
    return 0;
}