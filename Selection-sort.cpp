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
void select_sort(SSTable &ST,int len){
   for(int i=0;i<len-1;i++){
       int min=i;
       for(int j=i+1;j<len;j++){
           if(ST.elem[j]<ST.elem[min]){
               min=j;
           }
       }
       if(min!=i){
           Swap(ST.elem[i],ST.elem[min]);
       }
   }
}

int main(){
    SSTable ST;
    Init(ST,10);
    Pint(ST);
    select_sort(ST,10);
    Pint(ST);
    return 0;
}