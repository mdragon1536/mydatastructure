#include<stdio.h>
#include<stdlib.h>
#define TElemType int
int front=0,rear=0;
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
void EnQueue(BiTree *a,BiTree node)
{
    a[rear++]=node;
}
BiTNode *DeQueue(BiTNode **a)
{
    return a[front++];
}

void displayNode(BiTree node)
{
    printf("%d ",node->data);
}

int main(void)
{
    BiTree tree;
    CreateBiTree(&tree);
    BiTNode *p;
    BiTree a[20];
    EnQueue(a,tree);
    while(front<rear)
    {
        p=DeQueue(a);
        displayNode(p);
        if(p->lchild!=NULL)
            EnQueue(a,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(a,p->rchild);
    }
    return 0;
}
