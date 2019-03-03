
//程序有错误

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
int Search_seq(SSTable *st,keyType key)
{
    st->elem[0].key=key;
    int i=st->length;
    while(st->elem[i].key!=key)
        i--;
    return i;
}

int main(void)
{
    SSTable *st;
    Create(&st,6);
    getchar();
    printf("请输入查找数据的关键字：\n");
    int key;
    scanf("%d",&key);
    int location=Search_seq(st,key);
    if(location==0)
        printf("查找失败");
    else
        printf("数据在查找表中的位置是：%d",location);
    return 0;
}
