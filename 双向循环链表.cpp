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
    head->next=NULL;
    head->prior=NULL;
    head->data=1;
    line *list=head;
    for(int i=2;i<=5;i++)
    {
        line *body=(line*)malloc(sizeof(line));
        body->next=NULL;
        body->prior=NULL;
        body->data=i;

        list->next=body;
        body->prior=list;
        list=body;
    }
    list->next=head;
    head->prior=list;
    return head;
}

void display(line *head)
{
    line *temp=head;
    while(temp->next!=head)
    {
        if(temp->next==NULL);
            printf("%d\n",temp->data);
        else
            printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main(void)
{
    line *head;
    head=initLine(head);
    display(head);
    return 0;
}
