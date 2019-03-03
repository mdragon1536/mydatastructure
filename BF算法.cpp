#include<stdio.h>
#include<string.h>
int mate(char *B,char *A)
{
    int i=0,j=0;
    while(i<strlen(B)&&j<strlen(A))
    {
        if(B[i]==A[j])
        {
            i++;j++;
        }else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j==strlen(A))
        return i-strlen(A)+1;
    return 0;
}
int main(void)
{
    int number=mate("ababcabcacbab","abcac");
    printf("%d",number);
    return 0;
}
