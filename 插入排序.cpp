#include<stdio.h>
void print(int a[],int n,int i)
{
    printf("%d:",i);
    for(int j=0;j<8;j++)
        printf("%d",a[j]);
    printf("\n");
}
void InsertSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int j=i-1;
            int x=a[i];
            while(j>-1&&x<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=x;
        }
        print(a,n,i);
    }
}

int main(void)
{
    int a[8]={3,1,7,5,2,4,9,6};
    InsertSort(a,8);
    return 0;
}
