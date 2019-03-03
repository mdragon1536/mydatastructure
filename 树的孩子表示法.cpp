
//未按照预期效果运行

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define TElemType char
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}ChildPtr;
typedef struct
{
    TElemType data;
    ChildPtr *firstchild;
}CTBox;
typedef struct
{
    CTBox nodes[MAX_SIZE];
    int n,r;
}CTree;
CTree initTree(CTree tree)
{
    printf("输入节点数量：\n");
    scanf("%d",&(tree.n));
    for(int i=0;i<tree.n;i++)
    {
        printf("输入第%d个节点的值:\n",i+1);
        fflush(stdin);
        scanf("%c",&(tree.nodes[i].data));
        tree.nodes[i].firstchild=(ChildPtr*)malloc(sizeof(ChildPtr));
        tree.nodes[i].firstchild->next=NULL;

        printf("输入节点%c的孩子节点数量：\n",tree.nodes[i].data);
        int Num;
        scanf("%d",&Num);
        scanf("%d",&Num);
        if(!Num!=0)
        {
            ChildPtr *p=tree.nodes[i].firstchild;;
            for(int j=0;j<Num;j++)
            {
                ChildPtr *newEle=(ChildPtr*)malloc(sizeof(ChildPtr));
                newEle->next=NULL;
                printf("输入第%d个孩子节点在顺序表的位置",j+1);
                scanf("%d",&(newEle->child));
                p->next=newEle;
                p=p->next;
            }
        }
    }
    return tree;
}

void findKids(CTree tree,char a)
{
    int hasKids=0;
    for(int i=0;i<tree.n;i++)
    {
        if(tree.nodes[i].data==a)
        {
            ChildPtr *p=tree.nodes[i].firstchild->next;
            while(p)
            {
                hasKids=1;
                printf("%c ",tree.nodes[p->child].data);
                p=p->next;
            }
            break;
        }
    }
    if(hasKids==0)
        printf("此节点为叶子节点");
}

int main(void)
{
    CTree tree;
    tree=initTree(tree);
    tree.r=0;
    printf("找出节点F的所有孩子节点：");
    findKids(tree,'F');
    return 0;
}
