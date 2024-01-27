#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
int BST_Insert(BiTree &T,KeyType k){
    if(T==NULL){
        T=(BiTree) calloc(1,sizeof (BSTNode));
        T->key=k;
        return 1;
    }
    else if(k==T->key){
        return 0;
    }
    else if(k<T->key){
        return BST_Insert(T->lchild,k);
    }
    else{
        return BST_Insert(T->rchild,k);
    }

}
void Creat_BST(BiTree &T,KeyType* str,int len)
{
    int i;
    for(i=0;i<len;i++){
        BST_Insert(T,str[i]);
    }
}

void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->lchild);
        printf("%3d",p->key);
        InOrder(p->rchild);
    }
}

BiTree BST_Search(BiTree T,KeyType k,BiTree &parent){
    parent=NULL;
    while(T!=NULL&&k!=T->key){
        parent=T;
        if(k>T->key){
            T=T->rchild;
        }
        else{
            T=T->lchild;
        }
    }
    return T;
}


void DeleteNode(BiTree &root,KeyType x){
    if(root==NULL){
        return;
    }
    if(root->key>x){
        DeleteNode(root->lchild,x);
    }
    if(root->key<x){
        DeleteNode(root->rchild,x);
    }
    if(root->key==x){
        if(root->lchild==NULL){
            BiTree tem=root;
            root=root->rchild;
            free(tem);
        }
        else if(root->rchild==NULL){
            BiTree tem=root;
            root=root->lchild;
            free(tem);
        }
        else{
            BiTree tem=root->lchild;
            while(tem->rchild!=NULL){
                tem=tem->rchild;
            }
            root->key=tem->key;
            DeleteNode(root->lchild,tem->key);//传root的话刚替换完就会被删除因为当前根是tem->key
        }
    }
}



int main()
{
    BiTree T=NULL;
    KeyType str[7]={54,20,66,40,28,79,58};
    Creat_BST(T,str,7);
    InOrder(T);
    printf("\n");
    BiTree search,parent;
    search=BST_Search(T,58,parent);
    if(search){
        printf("find key:%d,its parents:%d\n",search->key,parent->key);
    }
    else{
        printf("error");
    }
    DeleteNode(T,54AA );
    InOrder(T);
    printf("\n");
    return 0;
}