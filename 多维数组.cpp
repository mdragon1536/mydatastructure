
//没能够运行出来，过程应该有错误

#include<stdio.h>
#include<stdarg.h>
#include<malloc.h>
#include<stdlib.h>//atoi()
#include<io.h>//eof()
#include<math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW 3
#define UNDERFLOW 4

typedef int Status;
typedef int Boolean;
typedef int ElemType;

#define MAX_ARRAY_DIM 8

typedef struct
{
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;
}Array;

Status InitArray(Array *A,int dim,...)
{
    int elemtotal=1,i;
    va_list ap;
    if(dim<1||dim>MAX_ARRAY_DIM)
        return ERROR;
    (*A).dim=dim;
    (*A).bounds=(int*)malloc(dim*sizeof(int));
    if(!(*A).bounds)
        exit(OVERFLOW);
    va_start(ap,dim);
    for(i=0;i<dim;++i)
    {
        (*A).bounds[i]=va_arg(ap,int);
        if((*A).bounds[i]<0)
            return UNDERFLOW;
        elemtotal*=(*A).bounds[i];
    }
    va_end(ap);
    (*A).base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!(*A).base)
        exit(OVERFLOW);
    (*A).constants[dim-1]=1;
    for(i=dim-2;i>=0;--i)
        (*A).constants[i]=(*A).bounds[i+1]*(*A).constants[i+1];
    return OK;
}

Status DestroyArray(Array *A)
{
    if((*A).base)
    {
        free((*A).base);
        (*A).base=NULL;
    }else
    return ERROR;
    if((*A).bounds)
    {
        free((*A).bounds);
        (*A).bounds=NULL;
    }else
    return ERROR;
    if((*A).constants)
    {
        free((*A).constants);
        (*A).constants=NULL;
    }
    else
        return ERROR;
    return OK;
}

Status Locate(Array A,va_list ap,int *off)
{
    int i,ind;
    *off=0;
    for(i=0;i<A.dim;i++)
    {
        ind=va_arg(ap,int);
        if(ind<0||ind>=A.bounds[i])
            return OVERFLOW;
        *off+=A.constants[i]*ind;
    }
    return OK;
}

Status Value(ElemType *e,Array A,...)
{
    va_list ap;
    Status result;
    int off;
    va_start(ap,A);
    if((result=Locate(A,ap,&off))==OVERFLOW)
        return result;
    *e=*(A.base+off);
    return OK;
}

Status Assign(Array *A,ElemType e,...)
{
    va_list ap;
    Status result;
    int off;
    va_start(ap,e);
    if((result=Locate(*A,ap,&off))==OVERFLOW)
        return result;
    *((*A).base+off)=e;
    return OK;
}

int main(void)
{
    Array A;
    int i,j,k,*p,dim=3,bound1=3,bound2=4,bound3=2;
    ElemType e,*p1;
    InitArray(&A,dim,bound1,bound2,bound3);
    p=A.bounds;
    printf("A.bounds=");
    for(i=0;i<dim;i++)
        printf("%d ",*(p+i));
    p=A.constants;
    printf("\nA.constants=");
    for(i=0;i<dim;i++)
        printf("%d ",*(p+i));
    printf("\n%d页%d行%d列矩阵元素如下：\n",bound1,bound2,bound3);
    for(i=0;i<bound1;i++)
    {
        for(j=0;j<bound2;j++)
        {
            for(k=0;k<bound3;k++)
            {
                Assign(&A,i*100+j*10+k,i,j,k);
                Value(&e,A,i,j,k);
                printf("A[%d][%d][%d]=%2d",i,j,k,e);
            }
            printf("\n");
        }
        printf("\n");
    }
    p1=A.base;
    printf("A.base=\n");
    for(i=0;i<bound1*bound2*bound3;i++)
    {
        printf("%4d",*(p1+i));
        if(i%(bound2*bound3)==bound2*bound3-1)
            printf("\n");
    }
    DestroyArray(&A);
    return 0;
}
