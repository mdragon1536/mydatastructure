
//没有按照预期的效果运行

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ElemType int
#define KeyType int
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int SearchBST(BiTree T,KeyType key,BiTree f,BiTree *p)
{
    if(!T)
    {
        *p=f;
        return FALSE;
    }
    else if(key==T->data)
    {
        *p=T;
        return TRUE;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key,T,p);
    else
        return SearchBST(T->rchild,key,T,p);
}

int InsertBST(BiTree *T,ElemType e)
{
    BiTree p=NULL;
    if(!SearchBST((*T),e,NULL,&p))
    {
        BiTree s=(BiTree)malloc(sizeof(BiTree));
        s->data=e;
        s->lchild=s->rchild=NULL;
        if(!p)
            *T=s;
        else if(e<p->data)
            p->lchild=s;
        else
            p->rchild=s;
        return TRUE;
    }
    return FALSE;
}

int Delete(BiTree *p)
{
    BiTree q,s;
    if(!(*p)->lchild&&!(*p)->rchild)
        *p=NULL;
    else if(!(*p)->lchild)
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else if(!(*p)->rchild)
    {
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    else
    {
        q=*p;
        s=(*p)->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;
        if(q!=*p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        free(s);
    }
    return TRUE;
}

int DeleteBST(BiTree *T,int key)
{
    if(!(*T))
        return FALSE;
    else
    {
        if(key==(*T)->data)
        {
            Delete(T);
            return TRUE;
        }
        else if(key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
    }
}

void order(BiTree t)
{
    if(t==NULL)
        return ;
    order(t->lchild);
    printf("%d",t->data);
    order(t->rchild);
}

int main(void)
{
    int i;
    int a[5]={3,4,2,5,9};
    BiTree T=NULL;
    for(i=0;i<5;i++)
    {
        InsertBST(&T,a[i]);
    }
    printf("中序遍历二叉排序树：\n");
    order(T);
    printf("\n");
    printf("删除3后，中序遍历二叉排序树：\n");
    DeleteBST(&T,3);
    order(T);
}
