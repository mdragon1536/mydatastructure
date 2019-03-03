#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct gambler
{
    int number;
}gambler;

int main(void)
{
    int n;
    int round=1;
    int location=1;
    int shootNum;
    int i,j;
    srand((int)time(0));
    printf("输入赌徒的人数：");
    scanf("%d",&n);
    printf("将赌徒依次编号为1-%\n",n);
    gambler gamblers[n+1];
    for(int i=1;i<=n;i++)
    {
        gamblers[i].number=i;
    }
    while(n!=1)
    {
        printf("第%d轮开始，从编号为%d的人开始，",round,gamblers[location].number);
        shootNum=rand()%6+1;
        printf("枪在第%d次扣动扳机时会响\n",shootNum);
        for(i=location;i<location+shootNum;i++);
        i=i%n;
        if(i==1||i==0)
            i=n+i;
        printf("编号为%d的赌徒退出赌博，剩余赌徒编号依次为：\n",gamblers[i-1].number);
        for(j=i-1;j+1<=n;j++)
        {
            gamblers[j]=gamblers[j+1];
        }
        n--;
        for(int k=1;k<=n;k++)
        {
            printf("%d ",gamblers[k].number);
        }
        printf("\n");
        location=i-1;
        if(location>n)
            location%=n;
        round++;
    }
    printf("最终胜利的赌徒编号为：%d\n",gamblers[1].number);
    return 0;
}
