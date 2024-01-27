#include <stdio.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top=-1;
}
bool StackEmpty(SqStack S){
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}
bool Push(SqStack &S,ElemType x){
    if(S.top==MAXSIZE-1){
        return false;
    }
    S.data[++S.top]=x;
    return true;
}
bool GetTop(SqStack S,ElemType &m){
    if(StackEmpty(S)){
        return false;
    }
    m=S.data[S.top];
    return true;
}
bool Pop(SqStack &S,ElemType &m){
    if(StackEmpty(S)){
        return false;
    }
    m=S.data[S.top--];
    return true;
}

int main(){
    SqStack S;
    InitStack(S);//初始化栈
    bool flag;
    flag=StackEmpty(S);
    if(flag){
        printf("Empty\n");
    }
    Push(S,3);
    Push(S,4);
    Push(S,5);
    ElemType m;
    flag=GetTop(S,m);
    if(flag){
        printf("get top:%d\n",m);
    }
    flag=Pop(S,m);
    if(flag){
        printf("pop :%d\n",m);
    }
    return 0;
}