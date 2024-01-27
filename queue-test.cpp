#include <stdio.h>

#define MAXSIZE 5
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}

bool IsEmpty(SqQueue Q){
    return Q.rear==Q.front;
}

bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MAXSIZE==Q.front){
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front){
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    bool ret;
    ret=IsEmpty(Q);
    if(ret){
        printf("Empty\n");
    }
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    ret=EnQueue(Q,7);
    if(ret){
        printf("success\n");
    }
    else{
        printf("false\n");
    }
    ElemType element;
    ret=DeQueue(Q,element);
    if(ret){
        printf("success\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}
