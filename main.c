/**************************
** 文件名:学生成绩管理系统
** 创建人:200111204杨昊坤
*************************/
#include <stdio.h>
#define N 30
int Readscore(int score[],long num[]);
void AveTotalscore(int score[],int n);
void ScoreSort(int score[],long num[],int n);
void NumSort(int score[],long num[],int n);
void PrintscoreLtoH(int score[],long num[],int n);
void PrintscoreHtoL(int score[],long num[],int n);
void PrintscoreNumLtoH(int score[],long num[],int n);
void Gradesort(int score[],int n);
int Search(int score[],long num[],int n);
void Menu();
float fAvenum;
int iTotalnum;

int main()
{
    printf("Number:200111204\n");
    printf("subject No.5 - program No.1\n\n");
    int score[N],i,n,flag1=0,flag2=0,ret;
    long num[N],x;
    int order;
    do
    {
        Menu();
         do{
                ret=scanf("%d",&order);                         //确保输入的为0——8的数字且第一次输入为1
                fflush(stdin);
                if(order==1)
                flag1=1;
                if(ret!=1||(order<0||order>8))
                {
                    printf("Input error!Please input again.\n");
                    Menu();
                }
                else if(ret==1&&flag1==0)
                {
                    printf("Please input 1 first\n");
                    Menu();
                }
            }while(ret!=1||flag1!=1);
        switch (order)
        {
            case 1:
                n=Readscore(score,num);
                break;
            case 2:
                AveTotalscore(score,n);
                break;
            case 3:
                PrintscoreHtoL(score,num,n);
                break;
            case 4:
                PrintscoreLtoH(score,num,n);
                break;
            case 5:
                PrintscoreNumLtoH(score,num,n);
                break;
            case 6:
                flag2=Search(score,num,n);
                if(flag2==-1)
                printf("num not found\n");
                    break;
            case 7:
                Gradesort(score,n);
                break;
            case 8:
                for(i=0;i<n;i++)
                {
                    printf("%ld\t%d\n",num[i],score[i]);
                }
                AveTotalscore(score,n);
                break;
            case 0:
                return 0;



        }

    } while (order!=0);


}
//函数功能：读入学号 成绩
int Readscore(int score[],long num[])
{
    int i,j,n,ret,flag=0;
    printf("Input the number of students:");
     do{
        ret=scanf("%d",&n);                                    //确保输入的为1-30的数字
        fflush(stdin);
        if(ret!=1||n>30||n<1)
        {
            printf("Input error!Please input again.\n");
            printf("Input the number of students:");
        }

    }while(ret!=1||n>30||n<1);
    for(i=0;i<n;i++)
    {
        do{
            printf("Input student's ID and score:");
            do{
                ret=scanf("%ld%d",&num[i],&score[i]);
                fflush(stdin);
                if(ret!=2||num[i]<0||score[i]<0||score[i]>100)
                {
                    printf("Input error!Please input again.\n");
                    printf("Input student's ID and score:");
                }
            }while(ret!=2||num[i]<0||score[i]<0||score[i]>100);         //确保输入学号为正数，成绩在0-100.
            if(i>0)
            {
                flag=0;
                for(j=0;j<i;j++)
                {
                    if(num[i]==num[j])
                    flag=1;
                }
                if(flag==1)
                printf("the student's number had been used!Please input again.\n");     //如果学号重复，则再次输入
            }
        }while(flag==1);
    }
    return n;
}
//函数功能：输出总分和平均数
void AveTotalscore(int score[],int n)
{
    int i=0;
    for(;i<n;i++)
    {
        iTotalnum=iTotalnum+score[i];
    }
    fAvenum=iTotalnum/n;
    printf("%d,%f\n",iTotalnum,fAvenum);
}
//函数功能：成绩排序
void ScoreSort(int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(score[j]>score[k])
                k=j;
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
}
//函数功能：学号排序
void NumSort(int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;

    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(num[j]<num[k])
                k=j;
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }

}
//函数功能：按成绩从高到低排序输出成绩
void  PrintscoreHtoL(int score[],long num[],int n)
{
    int i;
    ScoreSort(score,num,n);
    for(i=0;i<n;i++)
    {
        printf("%ld\t%d\n",num[i],score[i]);
    }
}
//函数功能：按成绩从低到高排序输出成绩
void  PrintscoreLtoH(int score[],long num[],int n)
{
    int i;
    ScoreSort(score,num,n);
    for(i=n-1;i>=0;i--)
    {
        printf("%ld\t%d\n",num[i],score[i]);
    }
}
//函数功能：按学号从低到高排序输出成绩
void PrintscoreNumLtoH(int score[],long num[],int n)
{
    int i;
    NumSort(score,num,n);
    for(i=n-1;i>=0;i--)
    {
        printf("%ld\t%d\n",num[i],score[i]);
    }
}
//函数功能：按学号查询
int Search(int score[],long num[],int n)
{
    int i;
    long x;
    ScoreSort(score,num,n);
    printf("Please input num:");
    scanf("%ld",&x);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        if (num[i]==x)
        {
            printf("rank:%d\n",i+1);
            printf("score：%d\n",score[i]);
            return 1;
        }
    }
    return -1;
}
//函数功能：将成绩分类并输出
void Gradesort(int score[],int n)
{
    int i;
    int grade[5]={0};
    float percent[5];
    for(i=0;i<n;i++)
    {
        if ((score[i]<=100)&&(score[i]>89))    grade[0]++;
        if ((score[i]<90)&&(score[i]>79))    grade[1]++;
        if ((score[i]<80)&&(score[i]>69))    grade[2]++;
        if ((score[i]<70)&&(score[i]>59))    grade[3]++;
        if ((score[i]<60)&&(score[i]>=0))    grade[4]++;
    }
    for(i=0;i<5;i++)
    {
        percent[i]=100*(float)grade[i]/n;
    }
    printf("excellent\t%d\t%f%%\n",grade[0],percent[0]);
    printf("good\t\t%d\t%f%%\n",grade[1],percent[1]);
    printf("medium\t\t%d\t%f%%\n",grade[2],percent[2]);
    printf("passed\t\t%d\t%f%%\n",grade[3],percent[3]);
    printf("unpassed\t%d\t%f%%\n",grade[4],percent[4]);
}
//函数功能：打印菜单
void Menu()
{
    printf("1. Input record\n");
    printf("2. Calculate total and average score of course\n");
    printf("3. Sort in descending order by score\n");
    printf("4. Sort in ascending order by score\n");
    printf("5. Sort in ascending order by number\n");
    printf("6. Search by number\n");
    printf("7. Statistic analysis\n");
    printf("8. List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
}

