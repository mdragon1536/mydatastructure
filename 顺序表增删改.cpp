#include<stdio.h>
#include<stdlib.h>
#define Size 5

typedef struct Table
{
    int *head;
    int length;
    int size;
}table;

table initTable()
{
    table t;
    t.head=(int*)malloc(Size*sizeof(int));
    if(!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}
//插入函数，elem为插入元素，add为插入到顺序表的位置
table addTable(table t,int elem,int add)
{
    if(add>t.length+1||add<1)
    {
        printf("插入位置有问题");
        return t;
    }
    if(t.length>=t.size)
    {
        t.head=(int*)malloc(Size*sizeof(int));
        if(!t.head)
        {
            printf("储存分配失败");
        }
        t.size+=1;
    }
    for(int i=t.length-1;i>=add-1;i--)
    {
        t.head[i+1]=t.head[i];
    }
    t.head[add-1]=elem;
    t.length++;
    return t;
}
//
table delTable(table t,int add)
{
    if(add>t.length||add<1)
    {
        printf("被删除元素的位置有误");
        exit(0);
    }
    for(int i=add;i<t.length;i++)
    {
        t.head[i-1]=t.head[i];
    }
    t.length--;
    return t;
}

int selectTable(table t,int elem)
{
    for(int i=0;i<t.length;i++)
    {
        if(t.head[i]==elem)
        {
            return i+1;
        }
    }
    return -1;
}
table amendTable(table t,int elem,int newElem)
{
    int add=selectTable(t,elem);
    t.head[add-1]=newElem;
    return t;
}

void displayTable(table t)
{
    for(int i=0;i<t.length;i++)
    {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}

int main(void)
{
    table t=initTable();
    for(int i=1;i<=Size;i++)
    {
        t.head[i-1]=i;
        t.length++;
    }
    printf("原顺序表为：\n");
    displayTable(t);

    printf("删除元素1：\n");
    t=delTable(t,1);
    displayTable(t);

    printf("在第2的位置上插入元素5：\n");
    t=addTable(t,5,2);
    displayTable(t);

    printf("查找元素3的位置：\n");
    int add=selectTable(t,3);
    printf("%d\n",add);

    printf("将元素3改为6：\n");
    t=amendTable(t,3,6);
    displayTable(t);

    return 0;
}
