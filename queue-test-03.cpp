#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;
typedef struct {
    LNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LNode*) malloc(sizeof(LNode));
    Q.rear->next= Q.front;
}

void EnQueue(LinkQueue &Q,int x){
    if(Q.front==Q.rear->next){
        LNode *pnew=(LNode*) malloc(sizeof(LNode));
        Q.rear->data=x;//值存在rear里面而不是front
        Q.rear->next=pnew;
        pnew->next=Q.front;
        Q.rear=pnew;
    }
    else{
        Q.rear->data=x;
        Q.rear=Q.rear->next;
    }
}

bool DeQueue(LinkQueue &Q){
    if(Q.front==Q.rear){
        return false;
    }
    else{
        printf("%2d",Q.front->data);
        Q.front=Q.front->next;
        return true;
    }
}




int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    bool ret;
    while(true) {
        ret= DeQueue(Q);
        if(!ret) {
            break;
        }
    }
    return 0;
}