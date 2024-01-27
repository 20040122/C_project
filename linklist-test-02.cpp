#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct  LNode* next;
}LNode,*LinkList;

void list_tail_insert(LinkList &L){
    ElemType x;
    L= (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LinkList p,r=L;
    scanf("%d",&x);
    while(x!=0){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=x;
        r->next=p;
        r=p;//尾节点
        scanf("%d",&x);
    }
    r->next=NULL;
}

void printf_list(LinkList L){
    L=L->next;
    while(L){
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}
//按位置查找
LinkList GetElem(LinkList L,int x){
    int i=0;
    while(L&&i<x){
        L=L->next;
        i++;
    }
    return L;
}
//按值查找
LinkList LocateElem(LinkList L,int x){
    while(L){
        if(L->data==x){
            return L;
        }
        else{
            L=L->next;
        }
    }
    return NULL;
}
void insert(LinkList L,int i,int j){
    LinkList p= GetElem(L,i-1);
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=j;
    q->next=p->next;
    p->next=q;
}


int main(){
    LinkList L;
    list_tail_insert(L);
    printf_list(L);
    LinkList search_01,search_02;
    search_01=GetElem(L,2);//查第二个位置的值
    if(GetElem){
        printf("%d\n",search_01->data);
    }
    search_02=LocateElem(L,3);//查三在哪个位置
    if(LocateElem){
        printf("%d\n",search_02->data);
    }
    insert(L,2,3);//向第2个位置插入3
    printf_list(L);
    return 0;
}
