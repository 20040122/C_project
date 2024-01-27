#include <stdio.h>
#define MAXSIZE 50
typedef int ElemType;//快速改变类型，类似于参数化
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;


bool ListInsert(SqList &L,int i,ElemType element)//因为L改变所以L要引用
{
    if(i<1||i>L.length+1){
        return false;
    }
    if(L.length==MAXSIZE){
        return false;
    }
    int j;
    for(j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=element;
    L.length++;
    return true;
}
void PrintList(SqList L){
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i] );
    }
    printf("\n");
}

bool ListDelete(SqList &L,int i,ElemType &element)//要得到element所以要用引用
{
    if(i<1||i>L.length){
        return false;
    }
    element=L.data[i-1];
    for(int j=i-1;j<L.length;j++){
        L.data[j]=L.data[j+1];
    }
    L.length--;
    return true;
}
int LocateElem(SqList L,int a){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==a){
            return i+1;
        } else{
            return 0;
        }
    }
}

int main(){
    SqList L;//结构体变量
    bool ret;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;
    //插入
    ret=ListInsert(L,4,60);
    if(ret){
        printf("success\n");
        PrintList(L);
    }
    else{
        printf("false");
    }
    //删除
    ElemType del;
    ret=ListDelete(L,2,del);
    if(ret){
        printf("success\n");
        printf("%d\n",del);
        PrintList(L);
    }
    else{
        printf("false");
    }
    //查找
    int b=LocateElem(L,100);
    if(b){
        printf("%d",b);
    }
    else{
        printf("false");
    }
    return 0;
}