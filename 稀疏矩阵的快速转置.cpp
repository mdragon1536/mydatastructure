#include<stdio.h>
#define number 10
typedef struct
{
    int i,j;
    int data;
}triple;
typedef struct
{
    triple data[number];
    int rpos[number];
    int n,m,num;
}TSMatrix;

TSMatrix fastTransposeMatrix(TSMatrix M,TSMatrix T)
{
    T.m=M.n;
    T.n=M.m;
    T.num=M.num;
    if(T.num)
    {
        int array[number];
        for(int col=1;col<=M.m;col++)
        {
            array[col]=0;
        }
        for(int t=0;t<M.num;t++)
        {
            int j=M.data[t].j;
            array[j]++;
        }

        int cpot[T.m+1];
        cpot[1]=1;
        for(int col=2;col<=M.m;col++)
            cpot[col]=cpot[col-1]+array[col-1];
        for(int p=0;p<M.num;p++)
        {
            int col=M.data[p].j;
            int q=cpot[col];

            T.data[q-1].i=M.data[p].j;
            T.data[q-1].j=M.data[p].i;
            T.data[q-1].data=M.data[p].data;
            cpot[col]++;
        }
    }
    return T;
}

int main()
{
    TSMatrix M;
    M.m=2;
    M.n=3;
    M.num=3;

    M.data[0].i=1;
    M.data[0].j=2;
    M.data[0].data=1;

    M.data[1].i=2;
    M.data[1].j=2;
    M.data[1].data=3;

    M.data[2].i=3;
    M.data[2].j=1;
    M.data[2].data=6;

    TSMatrix T;
    T=fastTransposeMatrix(M,T);
    printf("转置矩阵三元组表为：\n");
    for(int i=0;i<T.num;i++)
        printf("(%d,%d,%d)\n",T.data[i].i,T.data[i].j,T.data[i].data);
    return 0;
}
