#include<iostream>
#include<queue>
using namespace std;
const int N=10010;
const int INF=-1;   //用一个数表示当前二叉树节点为空的情况

struct Node
{
    int w;  //当前树节点的值
    int p;  //当前树节点的双亲所在组下标
    int l;  //当前树节点的左子节点所在数组下标
    int r;  //当前树节点的右节点所在的数组下标
};

Node node[N];

void input(int n)
{
    cin>>node[n].w;
    if(node[n].w==INF)
        return ;
    node[n].p=n/2;
    node[n].l=n*2;
    node[n].r=n*2+1;

    input(n*2);
    input(n*2+1);
}
//前序遍历二叉树
void preOrderParse(int n)
{
    if(node[n].w==INF)
        return ;
    cout<<node[n].w<<" ";
    preOrderParse(node[n].l);
    preOrderParse(node[n].r);
}
//中序遍历二叉树
void inOrderParse(int n)
{
    if(node[n].w==INF)
        return ;
    inOrderParse(n*2);
    cout<<node[n].w<<" ";
    inOrderParse(n*2+1);
}
//后序遍历二叉树
void postOrderParse(int n)
{
    if(node[n].w==INF)
        return;
    postOrderParse(n*2);
    postOrderParse(n*2+1);
    cout<<node[n].w<<" ";
}

//层序遍历
void sequenceParse()
{
    queue<int> que;
    int n=1;
    que.push(1);
    while(!que.empty())
    {
        n=que.front();
        que.pop();
        if(node[n].w!=INF)
        {
            cout<<node[n].w<<" ";
            que.push(node[n].l);
            que.push(node[n].r);
        }
    }
}

int main(void)
{
    cout<<"请以前序遍历的顺序输入二叉树，空节点输入-1："<<endl;
    input(1);

    cout<<"前序遍历："<<endl;
    preOrderParse(1);
    cout<<endl<<"中序遍历："<<endl;
    inOrderParse(1);
    cout<<endl<<"后序遍历："<<endl;
    postOrderParse(1);
    cout<<endl<<"层序遍历："<<endl;
    sequenceParse();
    return 0;
}
