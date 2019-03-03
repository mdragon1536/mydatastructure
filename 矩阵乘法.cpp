#include<stdio.h>
#define MAXSIZE 12500
#define MAXRC 100
#define ElemType int
typedef struct
{
    int i,j;
    ElemType e;
}Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int rpos[MAXRC+1];
    int mu,nu,tu;
}RLSMatrix;

RLSMatrix MultSMatrix(RLSMatrix A,RLSMatrix B,RLSMatrix C)
{
    if(A.nu!=B.mu)
        return C;
    C.mu=A.mu;
    C.nu=B.nu;
    C.tu=0;
    if(A.tu*B.tu==0)
        return C;
    else
    {
        int arow;
        int ccol;
        for(arow=1;arow<=A.mu;arow++)
        {
            int ctemp[MAXRC+1]={};
            C.rpos[arow]=C.tu+1;
            int tp;
            if(arow<A.mu)
                tp=A.rpos[arow+1];
            else
                tp=A.tu+1;

            int p;
            int brow;
            for(p=A.rpos[arow];p<tp;p++)
            {
                brow=A.data[p].j;
                int t;
                if(brow<B.mu)
                    t=B.rpos[brow+1];
                else
                    t=B.tu+1;
                int q;
                for(q=B.rpos[brow];q<t;q++)
                {
                    ccol=B.data[q].j;
                    ctemp[ccol]+=A.data[p].e*B.data[q].e;
                }
            }

            for(ccol=1;ccol<=C.nu;ccol++)

            {
                if(ctemp[ccol])
                {
                    if(++C.tu>MAXSIZE)
                        return C;
                    else
                    {
                        C.data[C.tu].e=ctemp[ccol];
                        C.data[C.tu].i=arow;
                        C.data[C.tu].j=ccol;
                    }
                }
            }
        }
        return C;
    }
}

int main()
{
    RLSMatrix M,N,T;

    M.tu=4;
    M.mu=3;
    M.nu=4;

    M.rpos[1]=1;
    M.rpos[2]=3;
    M.rpos[3]=4;

    M.data[1].e=3;
    M.data[1].i=1;
    M.data[1].j=1;

    M.data[2].e=5;
    M.data[2].i=1;
    M.data[2].j=4;

    M.data[3].e=-1;
    M.data[3].i=2;
    M.data[3].j=2;

    M.data[4].e=2;
    M.data[4].i=3;
    M.data[4].j=1;

    N.tu=4;
    N.mu=4;
    N.nu=2;

    N.rpos[1]=1;
    N.rpos[2]=2;
    N.rpos[3]=3;
    N.rpos[4]=5;

    N.data[1].e=2;
    N.data[1].i=1;
    N.data[1].j=2;

    N.data[2].e=1;
    N.data[2].i=2;
    N.data[2].j=1;

    N.data[3].e=-2;
    N.data[3].i=3;
    N.data[3].j=1;

    N.data[4].e=4;
    N.data[4].i=3;
    N.data[4].j=2;

    T=MultSMatrix(M,N,T);
    for(int i=1;i<=T.tu;i++)
        printf("(%d,%d,%d)\n",T.data[i].i,T.data[i].j,T.data[i].e);
    return 0;
}
