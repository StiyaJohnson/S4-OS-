#include<stdio.h>
#include<string.h>
struct process
{
    int AT,BT,WT,TT,visited,CT;
    char pname[10];
}p[10];

struct gantt
{
    int ST,CT;
    char gname[10];
}g[10];

void main()
{
    int i,n,j,time,count,index=0,idle=0;
    float wait,turn;
    printf("Enter the no: of processes\n");
    scanf("%d",&n);
    printf("enter the details\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name\n");
        scanf("%s",p[i].pname);
        printf("Enter the arrival time\n");
        scanf("%d",&p[i].AT);
        printf("Enter the burst time\n");
        scanf("%d",&p[i].BT);
        p[i].visited=0;
    }

    while(count<n)
    {
        int k,flag=0;
        for(j=0;j<n;j++)
        {
            if((p[j].visited==0) && (p[j].AT<=time) && (flag==0))
            {
                k=j;
                flag++;
            }
            if((p[j].visited==0) && (p[j].AT<=time) && (flag>0))
            {
                if(p[j].BT<p[k].BT)
                {
                    k=j;
                }
            }
        }

        if((flag==0) && (idle==0))
        {
            strcpy(g[index].gname,"idle");
            g[index].ST=time;
            idle=1;
            time++;
        }
        else if(flag>0)
        {
            if(idle==1)
            {
                g[index].CT=time;
                index++;
            }
            strcpy(g[index].gname,p[k].pname);
            g[index].ST=time;
            g[index].CT=time+p[k].BT;
         //   p[k].CT=g[index].CT;
            p[k].TT=g[index].CT-p[k].AT;
            p[k].WT=p[k].TT-p[k].BT;
            time=g[index].CT;
            count++;
            index++;
            p[k].visited=1;
            idle=0;
            k++;

        }
        else
        {
            time++;
        }
    }

    printf("Name\t|Arrival\t|Burst\t|TT\t|WT\n");
    printf("----------------------------------------------");
    for(i=0;i<n;i++)
    {
        printf("\n%s\t|%d\t\t|%d\t|%d\t|%d\n",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT);
        turn=turn+p[i].TT;
        wait=wait+p[i].WT;
    }
    printf("-----------------------------------------------");

    printf("\nThe gantt chart is\n");
    printf("----------------------------------------\n");
 //   printf("%d",g[0].ST);
    for(i=0;i<index;i++)
    {
        printf("%s\t|",g[i].gname);
    }
    printf("\n----------------------------------------\n");
    printf("%d\t",g[0].ST);
    for(i=0;i<index;i++)
    {
        printf("%d\t",g[i].CT);
    }

    printf("\nThe turnaround time is %f",turn/n);
    printf("\nThe waiting time is %f",wait/n);



}