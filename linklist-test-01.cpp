#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct  LNode* next;
}LNode,*LinkList;


void list_head_insert(LNode* &L){
    ElemType x;
    LinkList p;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=x;
        p->next=L->next;//新节点指向原本的第一个节点
        L->next=p;
        scanf("%d",&x);
    }
}

void printf_list(LinkList L){
    L=L->next;
    while(L){
        printf("%3d",L->data);
        L=L->next;
    }
}


int main(){
    LinkList L;
    list_head_insert(L);
    printf_list(L);
    return 0;
}
