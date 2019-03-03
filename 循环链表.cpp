#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}person;

person *initLink(int n)
{
    person *head=(person*)malloc(sizeof(person));
    head->number=1;
    head->next=NULL;
    person *cyclic=head;
    for(int i=2;i<=n;i++)
    {
        person *body=(person*)malloc(sizeof(person));
        body->number=i;
        body->next=NULL;
        cyclic->next=body;
        cyclic=body;
    }
    cyclic->next=head;
    return head;
}

void findAndKillK(person *head,int k,int m)
{
    person *tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    person *p=head;
    while(p->number!=k)
    {
        tail=p;
        p=p->next;
    }
    while(p->next!=p)
    {
        for(int i=1;i<m;i++)
        {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;
        printf("出列人的编号为：%d\n",p->number);
        free(p);
        p=tail->next;
    }
    printf("出列人的编号为：%d\n",p->number);
    free(p);
}

int main()
{
    printf("输入圆桌上的人数n:");
    int n;
    scanf("%d",&n);
    person *head=initLink(n);
    printf("从第k人开始报数:",n);
    int k;
    scanf("%d",&k);
    printf("数到m的人出列:");
    int m;
    scanf("%d",&m);
    findAndKillK(head,k,m);
    return 0;
}
