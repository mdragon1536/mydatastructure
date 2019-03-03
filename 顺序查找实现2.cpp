#include<stdio.h>
#include<stdlib.h>
#define keyType int
typedef struct
{
    keyType key;
}ElemType;
typedef struct
{
    ElemType *elem;
    int length;
}SSTable;
void Create(SSTable **st,int length)
{
    (*st)=(SSTable*)malloc(sizeof(SSTable));
    (*st)->length=length;
    (*st)->elem=(ElemType*)malloc((length+1)*sizeof(ElemType));
    printf("输入表中的数据元素：\n");
    for(int i=1;i<length;i++)
        scanf("%d",&((*st)->elem[i].key));
}
int search
