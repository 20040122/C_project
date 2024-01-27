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

void Insert_Sort(ElemType *A,int len){
    int i,j,insertVal;
    for(i=1;i<len;i++){//要插入的数是从下标1开始的
        insertVal=A[i];//保存要插入的数
        for(j=i-1;j>=0&&A[j]>insertVal;j--){
            A[j+1]=A[j];
        }
        A[j+1]=insertVal;//j=-1时将insertVal赋值给下标0位置
    }
}

int main(){
    SSTable ST;
    Init(ST,10);
    Pint(ST);
    Insert_Sort(ST.elem,10);
    Pint(ST);
    return 0;
}