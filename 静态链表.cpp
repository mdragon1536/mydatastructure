#include<stdio.h>
#define maxSize 6
typedef struct
{
    int data;
    int cur;
}component;
//创建备用链表
void reserveArr(component *myarray)
{
    for(int i=0;i<maxSize;i++)
    {
        myarray[i].cur=i+1;
    }
    myarray[maxSize-1].cur=0;
}

int mallocArr(component *myarray)
{
    int i=myarray[0].cur;
    if(myarray[0].cur)
    {
        myarray[0].cur=myarray[i].cur;
    }
    return i;
}

int initArr(component *myarray)
{
    reserveArr(myarray);
    int body=mallocArr(myarray);
    int tempBody=body;
    for(int i=1;i<4;i++)
    {
        int j=mallocArr(myarray);
        myarray[tempBody].cur=j;
        myarray[j].data=i;
        tempBody=j;
    }
    myarray[tempBody].cur=0;
    return body;
}

void displayArr(component *myarray,int body)
{
    int tempBody=body;
    while(myarray[tempBody].cur)
    {
        printf("%d,%d ",myarray[tempBody].data,myarray[tempBody].cur);
        tempBody=myarray[tempBody].cur;
    }
    printf("%d,%d \n",myarray[tempBody].data,myarray[tempBody].cur);
}

int main(void)
{
    component myarray[maxSize];
    int body=initArr(myarray);
    printf("静态链表为：\n");
    displayArr(myarray,body);
    return 0;
}
