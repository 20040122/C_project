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
void Swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;

}
//优先写内层
void Bubble_Sort(ElemType *elem,int len){
    int i;
    int j;
    for(i=0;i<len-1;i++){//外层控制有序数的数目
        for(j=len-1;j>i;j--){//j取不到0
            if(elem[j-1]>elem[j]){
                Swap(elem[j-1],elem[j]);
            }
        }
    }
}

int main(){
    SSTable ST;
    Init(ST,10);
    Pint(ST);
    Bubble_Sort(ST.elem,10);
    Pint(ST);
    return 0;
}