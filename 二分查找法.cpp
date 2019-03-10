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
    printf("输入表中的的数据元素：\n");
    for(int i=1;i<=length;i++)
        scanf("%d",&((*st)->elem[i].key));
}

int Search_Bin(SSTable *ST,keyType key)
{
    int low=1;
    int high=ST->length;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ST->elem[mid].key==key)
            return mid;
        else if(ST->elem[mid].key>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}

int main(void)
{
    SSTable *st;
    Create(&st,11);
    getchar();
    printf("输入查找数据的关键字：\n");
    int key;
    scanf("%d",&key);
    int location=Search_Bin(st,key);
    if(location==0)
        printf("查找表中无该元素");
    else
        printf("数据在查找表中的位置是：%d",location);
    return 0;
}
