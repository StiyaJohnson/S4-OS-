#include <stdio.h>
#include<string.h>
struct processor
{
    int at,bt,ct,wt,tt;
    char pname[10];
}p[5],temp;
struct gantt
{
    int st,ct;
    char name[10];
}g[5];
int main()
{
   int i,j,n,time=0,t;
   float tt=0.0,wt=0.0;
   printf("no.of p: ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("Enter the details of  \n");
       printf("Enter the name: \n");
       scanf("%s",p[i].pname);
       printf("Enter the arrival time: \n");
       scanf("%d",&p[i].at);
       printf("Enter the burst time: \n");
       scanf("%d",&p[i].bt);
   }
   printf("--------------------------------------------\n");
   printf("|name\t|at\t|bt\n");
   printf("\n--------------------------------------------\n");
   for(i=0;i<n;i++)
   {
       printf("|%s\t|%d\t|%d\n",p[i].pname,p[i].at,p[i].bt);
   }
       for(i=0;i<n;i++)
       {
           for(j=0;j<n-i-1;j++)
           {
               if(p[j].at>p[j+1].at)
               {
                   temp=p[j+1];
                   p[j+1]=p[j];
                   p[j]=temp;
               }
           }
       }
        printf("after sorted\n");
       printf("--------------------------------------------\n");
       printf("|name\t|at\t|bt\n");
       printf("\n--------------------------------------------\n");
       for(i=0;i<n;i++)
       {
           printf("|%s\t|%d\t|%d\n",p[i].pname,p[i].at,p[i].bt);
       }
     i=0;
   j=0;
   while(i<n)
   {  
      if(time>=p[i].at)
      {
          strcpy(g[j].name,p[i].pname);
          g[j].st=time;
          time=time+p[i].bt;
          g[j].ct=time;
          p[i].ct=time;
          p[i].tt=g[j].ct-p[i].at;
          p[i].wt=p[i].tt-p[i].bt;
          i++;
          j++;
      }
      else
      {
          strcpy(g[j].name,"idle");
          g[j].st=time;
          time=p[i].at;
          g[j].ct=time;
          j++;
      }
   }
   t=j;
        printf("--------------------------------------------\n");
       printf("|name\t|at\t|bt\t|ct\t|tt\t|wt\n");
       printf("--------------------------------------------\n");
       for(i=0;i<n;i++)
       {
           printf("|%s\t|%d\t|%d\t|%d\t|%d\t|%d\n",p[i].pname,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
            tt=p[i].tt+tt;
       wt=p[i].wt+wt;
       }
     
       printf("--------------------------------------------\n");
       for(i=0;i<t;i++)
       {
           printf("|%s\t",g[i].name);
       }
       printf("\n--------------------------------------------\n");
       printf("%d\t",g[i].st);
       for(i=0;i<t;i++)
       {
           printf("%d\t",g[i].ct);
       }
       printf("\nAvg tt=%f\n",tt/n);
       printf("Avg wt=%f\n",wt/n);
}

