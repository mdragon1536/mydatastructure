#include<stdio.h>
#include<stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
}link;

link *initLink()
{
    link *p=NULL;
    link *temp=(link*)malloc(sizeof(link));
    temp->elem=1;
    temp->next=NULL;
    p=temp;
    for(int i=2;i<5;i++)
    {
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=a;
    }
    return p;
}

void display(link *p)
{
    link *temp=p;
    while(temp)
    {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}

int main(void)
{
    printf("��ʼ������Ϊ��\n");
    link *p=initLink();
    display(p);
    return 0;
}
