#include "function.h"
//前序
void PreOrder(BiTree p)
{
    if(p!=NULL) {
        printf("%c", p->c);
        PreOrder(p->lchhid);
        PreOrder(p->rchhid);
    }
}
//中序
void InOrder(BiTree p)
{
    if(p!=NULL){
        InOrder(p->lchhid);
        printf("%c",p->c);
        InOrder(p->rchhid);
    }
}
//后序
void PostOrder(BiTree p)
{
    if(p!=NULL){
        PostOrder(p->lchhid);
        PostOrder(p->rchhid);
        printf("%c",p->c);
    }
}

int main(){
    BiTree pnew;//指向新节点
    BiTree tree=NULL;//指向树根
    char c;
    ptag_t ptail=NULL,listpnew=NULL,pcur=NULL;//辅助队列
    while(scanf("%c",&c)){
        if(c=='\n'){
            break;
        }
        //calloc申请空间大小为两个空间相乘,空间初始化为0
        pnew= (BiTree)calloc(1,sizeof (BiNode));
        pnew->c=c;

        listpnew=(ptag_t)calloc(1,sizeof (tag_t));
        listpnew->p=pnew;

        if(tree==NULL){
            tree=pnew;
            ptail=listpnew;
            pcur=listpnew;
            continue;
        }
        else{
            ptail->pnext=listpnew;
            ptail=listpnew;
            if(pcur->p->lchhid==NULL)
            {
                pcur->p->lchhid=pnew;
            }
            else if(pcur->p->rchhid==NULL)
            {
                pcur->p->rchhid=pnew;
                pcur=pcur->pnext;//左右孩子都有指向下一个节点
            }
        }
    }
    printf("前序遍历：\n");
    PreOrder(tree);
    printf("\n");
    printf("中序遍历：\n");
    InOrder(tree);
    printf("\n");
    printf("后序遍历：\n");
    PostOrder(tree);
    return 0;
}