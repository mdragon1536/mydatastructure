#include<stdio.h>
int set[5];
void PowerSet(int i,int n)
{
    if(i>n)
    {
        for(int j=1;j<=n;j++)
        {
            if(set[j]==1)
                printf("%d ",j);
        }
        printf("\n");
    }
    else
    {
        set[i]=1;
        PowerSet(i+1,n);
        set[i]=0;
        PowerSet(i+1,n);
    }
}

int main()
{
    int n=3;
    for(int i=0;i<5;i++)
    {
        set[i]=0;
    }
    PowerSet(1,n);
    return 0;
}
