#include<stdio.h>
#include<stdlib.h>
typedef struct line
{
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initLine(line *head)
{
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line *list=head;
    for(int i=2;i<=5;i++)
    {
        line *body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        list->next=body;
        body->prior=list;

        list=list->next;
    }
    return head;
}

void display(line *head)
{
    line *temp=head;
    while(temp)
    {
        if(temp->next==NULL)
        {
            printf("%d\n",temp->data);
        }else
        {
            printf("%d <-> ",temp->data);
        }
        temp=temp->next;
    }
}

int main()
{
    line *head=NULL;
    head=initLine(head);
    display(head);
    printf("链表中第四个节点的直接前驱是：%d",head->next->next->next->prior->data);
    return 0;
}
