#include <stdio.h>
#include <stdlib.h>
typedef int BiElemType;
typedef struct BiNode{
    BiElemType weight;
    struct BiNode* lchhid;
    struct BiNode* rchhid;
}BiNode,*BiTree;

typedef struct tag{
    BiTree p;
    struct tag* pnext;
}tag_t,*ptag_t;


int wpl_PreOrder(BiTree p,int deep)
{
    static int wpl=0;//和全局变量类似，只初始化一次，只在函数内有效
    if(p!=NULL) {
        if(p->lchhid==NULL&&p->rchhid==NULL){
            wpl+=p->weight*deep;
        }
        wpl_PreOrder(p->lchhid,deep+1);
        wpl_PreOrder(p->rchhid,deep+1);
    }
    return wpl;
}
int WPL(BiTree tree)
{
   return wpl_PreOrder(tree,0);
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
        pnew->weight=c;

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
    printf("%d", WPL(tree));
    return 0;
}