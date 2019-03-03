#include<stdio.h>
#define max 5
int enQueue(int *a,int front,int rear,int data)
{
    if((rear+1)%max==front)
    {
        printf("空间已满");
        return rear;
    }
    a[rear%max]=data;
    rear++;
    return rear;
}
int deQueue(int *a,int front,int rear)
{
    if(front==rear%max)
    {
        printf("队列为空");
        return front;
    }
    printf("%d\n",a[front]);
    front=(front+1)%max;
    return front;
}

int main()
{
    int a[max];
    int front,rear;
    front=rear=0;
    rear=enQueue(a,front,rear,1);
    rear=enQueue(a,front,rear,2);
    rear=enQueue(a,front,rear,3);
    rear=enQueue(a,front,rear,4);
    //出队
    front=deQueue(a,front,rear);
    //再入队
    rear=enQueue(a,front,rear,5);
    //再出队
    front=deQueue(a,front,rear);
    //再入队
    rear=enQueue(a,front,rear,6);
    //再出队
    front=deQueue(a,front,rear);
    front=deQueue(a,front,rear);
    front=deQueue(a,front,rear);
    front=deQueue(a,front,rear);

    return 0;
}
