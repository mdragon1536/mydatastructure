
//无法运行出来

#include<stdio.h>
#define MAX_VERtEX_NUM 20
#define VRType int
#define InfoType char
#define VertexType int
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef struct
{
    VRType adj;
    InfoType *info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERtEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
    GraphKind kind;
}MGraph;
int LocateVex(MGraph *G,VertexType v)
{
    int i=0;
    for(;i<G->vexnum;i++)
    {
        if(G->vexs[i]==v)
            break;
    }
    if(i>G->vexnum)
    {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

void CreateDG(MGraph *G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++)
        scanf("%d",&(G->vexs[i]));

    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for(int i=0;i<G->arcnum;i++)
    {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(G,v1);
        int m=LocateVex(G,v2);
        if(m==-1||n==-1)
        {
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m].adj=1;
    }
}

void CreateDN(MGraph *G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++)
        scanf("%d",&(G->vexs[i]));

    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for(int i=0;i<G->arcnum;i++)
    {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(G,v1);
        int m=LocateVex(G,v2);
        if(m==-1||n==-1)
        {
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;
    }
}

void CreateUDG(MGraph *G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++)
        scanf("%d",&(G->vexs[i]));

    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for(int i=0;i<G->arcnum;i++)
    {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G,v1);
        int m=LocateVex(G,v2);
        if(m==-1||n==-1)
        {
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m].adj=w;
    }
};

void CreateUDN(MGraph *G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++)
    {
        scanf("%d",&(G->vexs[i]));
    }

    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }

    for(int i=0;i<G->arcnum;i++)
    {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int m=LocateVex(G,v1);
        int n=LocateVex(G,v2);
        if(m==-1||n==-1)
        {
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}

void CreateGraph(MGraph *G)
{
    scanf("%d",&(G->kind));
    switch(G->kind)
    {
    case DG:
        return CreateDG(G);
        break;
    case DN:
        return CreateDN(G);
        break;
    case UDG:
        return CreateUDG(G);
        break;
    case UDN:
        return CreateUDN(G);
        break;
    default:
        break;
    }
}

void PrintGraph(MGraph G)
{
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            printf("%d ",G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

int main(void)
{
    MGraph G;
    CreateGraph(&G);
    PrintGraph(G);
    return 0;
}
