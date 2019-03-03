
//没有按照预期的效果运行

#include<stdio.h>
#include<stdlib.h>
typedef struct GLNode
{
    int tag;
    union
    {
        char atom;
        struct
        {
            struct GLNode *hp,*tp;
        }ptr;
    };
}*Glist,GNode;

Glist creatGlist(Glist C)
{
    //广义表
    C=(Glist)malloc(sizeof(GNode));
    C->tag=1;

    //表头原子‘a’
    C->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.hp->tag=0;
    C->ptr.hp->atom='a';

    //表尾子表（b,c,d）是一个整体
    C->ptr.tp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.hp->ptr.tp=NULL;

    C->ptr.tp->ptr.hp->tag=1;
    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.hp->atom='b';
    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(GNode));

    C->ptr.tp->ptr.hp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));

    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;

    return C;
}

void copyGlist(Glist C,Glist *T)
{
    if(!C)
    {
        *T=NULL;
    }
    else
    {
        *T=(Glist)malloc(sizeof(GNode));
        if(!*T)
            exit(0);
        (*T)->tag=C->tag;
        if(C->tag==0)
            (*T)->atom=C->atom;
        else
        {
            copyGlist(C->ptr.hp,&((*T)->ptr.hp));
            copyGlist(C->ptr.hp,&((*T)->ptr.tp));
        }
    }
}

int main()
{
    Glist C=NULL;
    C=creatGlist(C);
    Glist T=NULL;
    copyGlist(C,&T);
    printf("%c",T->ptr.hp->atom);
    return 0;
}
