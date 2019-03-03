#include<stdio.h>
int enQueue(int *a,int rear,int data)
{
    a[rear]=data;
    rear++;
    return rear;
}
void deQueue(int *a,int front,int rear)
{
    while(front!=rear)
    {
        printf("³ö¶ÓÔªËØ£º%d\n",a[front]);
        front++;
    }
}
int main(void)
{
    int a[100];
    int front,rear;
    front=rear=0;
    rear=enQueue(a,rear,1);
    rear=enQueue(a,rear,2);
    rear=enQueue(a,rear,3);
    rear=enQueue(a,rear,4);
    deQueue(a,front,rear);
    return 0;
}
