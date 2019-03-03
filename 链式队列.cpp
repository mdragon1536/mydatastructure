#include<stdio.h>
#include<stdlib.h>
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;
QNode *initQueue()
{
    QNode *queue=(QNode*)malloc(sizeof(QNode));
    queue->next=NULL;
    return queue;
}
QNode *enQueue(QNode *rear,int data)
{
    QNode *enElem=(QNode*)malloc(sizeof(QNode));
    enElem->data=data;
    enElem->next=NULL;
    rear->next=enElem;
    rear=enElem;
    return rear;
}
void DeQueue(QNode *top,QNode *rear)
{
    if(top->next==NULL)
    {
        printf("\n¶ÓÁÐÎª¿Õ");
        return ;
    }
    QNode *p=top->next;
    printf("%d ",p->data);
    top->next=p->next;
    if(rear==p)
        rear=top;
    free(p);
}
int main(void)
{
    QNode *queue,*top,*rear;
    queue=top=rear=initQueue();
    rear=enQueue(rear,1);
    rear=enQueue(rear,2);
    rear=enQueue(rear,3);
    rear=enQueue(rear,4);

    DeQueue(top,rear);
    DeQueue(top,rear);
    DeQueue(top,rear);
    DeQueue(top,rear);
    DeQueue(top,rear);
    return 0;
}
