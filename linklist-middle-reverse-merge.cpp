#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;
void create(NODE* &L) {
    int x;
    L = (NODE *) malloc(sizeof(NODE));
    L->next=NULL;
    NODE *r=L, *p;
    scanf("%d", &x);
    while (x != 0) {
        p = (NODE *) malloc(sizeof(NODE));
        p->data = x;
        r->next = p;
        r = p;
        scanf("%d", &x);
    }
    r->next = NULL;
}
void print(NODE* L){
    L=L->next;
    while(L){
        printf("%d  ",L->data);
        L=L->next;
    }
    printf("\n");
}
void middle(NODE *L,NODE *&L2){
    L2=(NODE*)malloc(sizeof(NODE));
    NODE *pcur,*ppre;//双指针法找中间节点
    pcur=ppre=L->next;//两个指针的起始位置都为L链表的第一的节点，pcur每次走两步，ppre每次走一步代表中间节点
    while(pcur){
        pcur=pcur->next;
        if(pcur==NULL){
            break;
        }
        pcur=pcur->next;
        if(pcur==NULL){
            break;
        }//偶数1234 ppre指向2，而不是3
        ppre=ppre->next;
    }
    L2->next=ppre->next;//中间节点后面的节点为L2的第一个节点
    ppre->next=NULL;//ppre作为L的链表尾
}
void reverse(NODE *L2){
    NODE *r,*s,*t;
    r=L2->next;
    if(r==NULL){
        return;
    }
    s=r->next;
    if(s==NULL){
        return;
    }
    t=s->next;
    while(t){
        s->next=r;
        r=s;
        s=t;
        t=t->next;
    }
    s->next=r;
    L2->next->next=NULL;//L2->next最初指向r，r现在为反转链表的表尾
    L2->next=s;//s为反转链表的表头
}
void merge(NODE *L,NODE *L2){
    NODE *pcur,*p,*q;
    pcur=L->next;//pcur一直指向新链表的表尾
    p=pcur->next;//eg:1 2 3 4 5,pcur指向1，p指向2
    q=L2->next;
    while(p!=NULL&&q!=NULL){
        pcur->next=q;
        q=q->next;
        pcur=pcur->next;
        pcur->next=p;
        p=p->next;
        pcur=pcur->next;
    }
    if(p!=NULL){
        pcur->next=p;
    }
    if(q!=NULL){
        pcur->next=q;
    }
}
int main(){
    NODE* L;
    create(L);
    print(L);
    NODE* L2;
    middle(L,L2);
    printf("------------------\n");
    print(L2);
    reverse(L2);
    printf("------------------\n");
    print(L2);
    printf("------------------\n");
    merge(L,L2);
    print(L);
    return 0;
}