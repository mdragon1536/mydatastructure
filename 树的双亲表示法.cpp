#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef char ElemType;
typedef struct Snode
{
    ElemType data;
    int parent;
}PNode;
typedef struct
{
    PNode tnode[MAX_SIZE];
    int n;
}PTree;
PTree InitPNode(PTree tree)
{
    int i,j;
    char ch;
    printf("请输入节点的个数:\n");
    scanf("%d",&(tree.n));

    printf("请输入节点的值其双亲位于数组中的位置下标：\n");
    for(int i=0;i<tree.n;i++)
    {
        fflush(stdin);
        scanf("%c %d",&ch,&j);
        tree.tnode[i].data=ch;
        tree.tnode[i].parent=j;
    }
    return tree;
}
void FindParent(PTree tree)
{
    char a;
    int isfind=0;
    printf("请输入要查询的节点值:\n");
    fflush(stdin);
    scanf("%c",&a);
    for(int i=0;i<tree.n;i++)
    {
        if(tree.tnode[i].data==a)
        {
            isfind=1;
            int ad=tree.tnode[i].parent;
            printf("%c的父节点为%c,储存位置下标为 %d",a,tree.tnode[ad].data,ad);
            break;
        }
    }
    if(isfind==0)
        printf("树中无此节点");
}
int main(void)
{
    PTree tree;
    tree=InitPNode(tree);
    FindParent(tree);
    return 0;
}
