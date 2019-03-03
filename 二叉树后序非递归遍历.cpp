#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TElemType int
int top=-1;
typedef struct BiTNode
{
    TElemType  data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree *T)
{
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));

    (*T)->lchild->data=2;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=NULL;
    (*T)->rchild->data=3;
    (*T)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
}

void pop()
{
    if(top==-1)
        return ;
    top--;
}

void displayElem(BiTNode *elem)
{
    printf("%d ",elem->data);
}

typedef struct SNode
{
    BiTree p;
    int tag;
}SNode;

void postpush(SNode *a,SNode sdata)
{
    a[++top]=sdata;
}

void PostOrderTraverse(BiTree Tree)
{
    SNode a[20];
    BiTNode *p;
    int tag;
    SNode sdata;
    p=Tree;
    while(p||top!=-1)
    {
        while(p)
        {
            sdata.p=p;
            sdata.tag=0;
            postpush(a,sdata);
            p=p->lchild;
        }
        sdata=a[top];
        pop();
        p=sdata.p;
        tag=sdata.tag;
        if(tag==0)
        {
            sdata.p=p;
            sdata.tag=1;
            postpush(a,sdata);
            p=p->rchild;
        }
        else
        {
            displayElem(p);
            p=NULL;
        }
    }
}

int main(void)
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("∫Û–Ú±È¿˙£∫\n");
    PostOrderTraverse(Tree);
}
