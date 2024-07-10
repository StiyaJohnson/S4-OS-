#include<stdio.h>
#include<string.h>
struct process
{
    char name[5];
    int at, bt, wt, tt, left, status,pt;
}p[10];
struct gantt
{
    char name[5];
    int st,ct;
}g[50];
void main()
{
    int n,m,i=0,k=0,j=0,flag,num=0,ls=0,idle=0;
    float ttt=0,twt=0;
    printf("Enter no.of process\n");
    scanf("%d",&n);
    for( m=0;m<n;m++)
    {
        printf("enter name,arival time,burst time,priority\n");
        scanf("%s%d%d%d",p[m].name,&p[m].at,&p[m].bt,&p[m].pt);
        p[m].status=0;
        p[m].left=p[m].bt;
    }
    
    while(ls<n)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if((p[j].status==0)&&(p[j].at<=i)&&(flag==0))
            {
                k=j;
                flag++;
            }
            if((p[j].status==0)&&(p[j].at<=i)&&(flag>0))
            {
                if(p[k].pt>p[j].pt)
                {
                    k=j;
                }
            }
        }
        if ((flag==0)&&(idle==0))
        {
            strcpy(g[num].name,"idle");
            g[num].st=i;
            idle=1;
            i++;
        }
        else if (flag>0)
        {
            if(idle==1)
            {
                g[num].ct=i;
                idle=0;
                num++;
            }
            strcpy(g[num].name,p[k].name);
            g[num].st=i;
             if(p[k].left<=1)
            {
               i=i+p[k].left; 
                g[num].ct=i;
                p[k].tt=g[num].ct-p[k].at;
                p[k].wt=p[k].tt-p[k].bt;
                p[k].status=1;
                num++;
                ls++;
            }
            else
            {
                i=i+1;
                g[num].ct=i;
                p[k].left=p[k].left-1;
                num++;
            }
        }
        else
        {
            i++;
        }
    }
    
    printf("process\t\tAT\t\tBT\t\tPRIORITY\t\tTT\t\tWT\n");
    for( i=0;i<n;i++)
    {
        			printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].pt,p[i].tt,p[i].wt);
         ttt=ttt+p[i].tt;
         twt=twt+p[i].wt;
    }
    printf("GANTT CHART\n");
    printf("_________________________________________________________________________________________\n");
    for( i=0;i<num;i++)
    {
        if(strcmp(g[i].name,g[i+1].name)==0)
        {
            continue;
        }
        else
        {
            printf("|%s\t\t",g[i].name);
        }
    }
    printf("|\n");
    printf("_________________________________________________________________________________________\n");
    printf("%d\t\t",g[0].st);
    for(i=0;i<num;i++)
    {
        if(strcmp(g[i].name,g[i+1].name)==0)
        {
            continue;
        }
        else
        {
            printf("%d\t\t",g[i].ct);
        }
    }
    printf("\n");
    printf("average turnaround time = %f",ttt/n);
    printf("average waiting time = %f",twt/n);
}