#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define linkNum 3
typedef struct Link
{
    char a[linkNum];
    struct Link *next;
}link;
link *initLink(link *head,char *str)
{
    int length=strlen(str);
    int num=length/linkNum;
    if(length%linkNum)
        num++;
    head=(link*)malloc(sizeof(link));
    head->next=NULL;
    link *temp=head;
    for(int i=0;i<num;i++)
    {
        int j=0;
        for(;j<linkNum;j++)
        {
            if(i*linkNum+j<length)
                temp->a[j]=str[i*linkNum+j];
            else
                temp->a[j]='#';
        }
        if(i*linkNum+j<length)
        {
            link *newlink=(link*)malloc(sizeof(link));
            newlink->next=NULL;
            temp->next=newlink;
            temp=newlink;
        }
    }
    return head;
}
void displayLink(link *head)
{
    link *temp=head;
    while(temp)
    {
        for(int i=0;i<linkNum;i++)
            printf("%c",temp->a[i]);
        temp=temp->next;
    }
}

int main(void)
{
    link *head=NULL;
    head=initLink(head,"data.biancheng.net");
    displayLink(head);
    return 0;
}
