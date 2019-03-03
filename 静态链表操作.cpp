#include<stdio.h>
#define maxSize 6
typedef struct
{
    char data;
    int cur;
}component;
void reserveArr(component *myArr);
int initArr(component *myArr);
void insertArr(component *myArr,int body,int add,char a);
void deletArr(component *myArr,int body,char a);
int selectElem(component *myArr,int body,char elem);
void amendElem(component *myArr,int body,char oldElem,char newElem);
void displayArr(component *myArr,int body);
int mallocArr(component *myArr);
void freeArr(component *myArr,int k);

int main(void)
{
    component myArr[maxSize];
    int body=initArr(myArr);
    printf("静态链表为：\n");
    displayArr(myArr,body);

    printf("在第3的位置上插入结点‘e’：\n");
    insertArr(myArr,body,3,'e');
    displayArr(myArr,body);

    printf("删除数据域为‘a’的节点：\n");
    deletArr(myArr,body,'a');
    displayArr(myArr,body);

    printf("查找的数据域为‘e’的节点的位置是：\n");
    int selectAdd=selectElem(myArr,body,'e');
    printf("%d\n",selectAdd);
    printf("将节点数据域为‘e’改为‘h’：\n");
    amendElem(myArr,body,'e','h');
    displayArr(myArr,body);

    return 0;
}

void reserveArr(component *myArr)
{
    for(int i=0;i<maxSize;i++)
    {
        myArr[i].cur=i+1;
    }
    myArr[maxSize-1].cur=0;
}

int initArr(component *myArr)
{
    reserveArr(myArr);
    int body=mallocArr(myArr);
    int tempBody=body;
    for(int i=1;i<5;i++)
    {
        int j=mallocArr(myArr);
        myArr[tempBody].cur=j;
        myArr[j].data='a'+i-1;
        tempBody=j;
    }
    myArr[tempBody].cur=0;
    return body;
}

void insertArr(component *myArr,int body,int add,char a)
{
    int tempBody=body;
    for(int i=1;i<add;i++)
    {
        tempBody=myArr[tempBody].cur;
    }
    int myinsert=mallocArr(myArr);
    myArr[myinsert].cur=myArr[tempBody].cur;
    myArr[myinsert].data=a;
    myArr[tempBody].cur=myinsert;
}

void deletArr(component *myArr,int body,char a)
{
    int tempBody=body;
    while(myArr[tempBody].data!=a)
    {
        tempBody=myArr[tempBody].cur;
        if(tempBody==0)
        {
            printf("链表中没有此数据");
            return ;
        }
    }
    int del=tempBody;
    tempBody=body;
    while(myArr[tempBody].cur!=del)
    {
        tempBody=myArr[tempBody].cur;
    }
    myArr[tempBody].cur=myArr[del].cur;
    freeArr(myArr,del);
}

int selectElem(component *myArr,int body,char elem)
{
    int tempBody=body;
    while(myArr[tempBody].cur!=0)
    {
        if(myArr[tempBody].data==elem)
        {
            return tempBody;
        }
        tempBody=myArr[tempBody].cur;
    }
    return -1;
}

void amendElem(component *myArr,int body,char oldElem,char newElem)
{
    int add=selectElem(myArr,body,oldElem);
    if(add==-1)
    {
        printf("无更改元素");
        return;
    }
    myArr[add].data=newElem;
}

void displayArr(component *myArr,int body)
{
    int tempBody=body;
    while(myArr[tempBody].cur)
    {
        printf("%c,%d ",myArr[tempBody].data,myArr[tempBody].cur);
        tempBody=myArr[tempBody].cur;
    }
    printf("%c,%d\n",myArr[tempBody].data,myArr[tempBody].cur);
}

int mallocArr(component *myArr)
{
    int i=myArr[0].cur;
    if(myArr[0].cur)
    {
        myArr[0].cur=myArr[i].cur;
    }
    return i;
}

void freeArr(component *myArr,int k)
{
    myArr[k].cur=myArr[0].cur;
    myArr[0].cur=k;
}


