#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TElemType int
int top=-1;
typedef struct BiTNode
{
    TElemType data;
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

void push(BiTNode **a,BiTNode *elem)
{
    a[++top]=elem;
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

BiTNode *getTop(BiTNode **a)
{
    return a[top];
}

void PreOrderTraverse(BiTree Tree)
{
    BiTNode *a[20];
    BiTNode *p;
    push(a,Tree);
    while(top!=-1)
    {
        p=getTop(a);
        pop();
        while(p)
        {
            displayElem(p);
            if(p->rchild)
                push(a,p->rchild);
            p=p->lchild;
        }
    }
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("���������\n");
    PreOrderTraverse(Tree);
}
