#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
void AjustDown(int A[],int k,int len){
    int dad=k;
    int son=2*dad+1;
    while(son<len){
        if(son+1<len&&A[son]<A[son+1]){//右孩子大拿右孩子
            son++;
        }
        if(A[son]>A[dad]){
            Swap(A[son],A[dad]);
            dad=son;//交换以后dad值改变,判断下面的子树
            son=2*dad+1;
        }
        else{
            break;
        }
    }

}

void heap_sort(int A[],int len){
    //1.调整为大根堆
    int i;
    for(i=len/2-1;i>=0;i--){
        AjustDown(A,i,len);
    }
    //2.交换根部元素和最后一个元素
    Swap(A[0],A[len-1]);
    for(i=len-1;i>1;i--){//i代表无序数组长度
        AjustDown(A,0,i);
        Swap(A[0],A[i-1]);
    }
}


int main(){
    SSTable ST;
    Init(ST,10);
//    int A[10]={3,87,2,93,78,56,61,38,12,40};
//    memcpy(ST.elem,A,sizeof(A));
    Pint(ST);
    heap_sort(ST.elem,10);
    Pint(ST);
    return 0;
}