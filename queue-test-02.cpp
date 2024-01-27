#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *p=(LinkNode*)malloc(sizeof(LinkNode));
    p->data=x;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}
bool DeQueue(LinkQueue &Q,ElemType &m){
    if(Q.rear==Q.front){
        return false;
    }
    LinkNode *q;
    q=Q.front->next;
    m=q->data;
    Q.front->next=q->next;
    if(Q.rear==q){
        Q.rear=Q.front;
    }
    free(q);
    return true;
}


int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    EnQueue(Q,7);
    ElemType m;
    bool ret;
    ret=DeQueue(Q,m);
    if(ret){
        printf("%d",m);
    }
    return 0;
}
