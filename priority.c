#include<stdio.h>
#include<unistd.h>
#define MAX 10
struct process
{
	int at,bt,ct,no,tt,wt,p;
};
void main()
{
	int loc,time,i,n,j,g;
	float tat=0,twt=0;
	struct process p[MAX],key,gant[MAX],idle,min;
	printf("Enter the number of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival time, Burst Time and Priority of process %d : \n",i+1);
		scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].p);
		p[i].no=i+1;
	}
	for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j].at > key.at) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
	idle.bt=0;
	for(i=0,g=0,time=0;i<n;i++)
	{
		if(time<p[i].at)
		{
			gant[g]=idle;
    		gant[g++].ct=time=p[i--].at;
		}
		else
		{	
			loc=i;
    		for(j=i,min.p=p[j].p;j<n&&p[j].at<=time;j++)
    		{
    			if(p[j].p<min.p)
    			{
    				min=p[j];
    				loc=j;
    			}
    		}
    		if(i!=loc)
    		{
    			p[loc]=p[i];
    			p[i]=min;
    		}
    		time+=p[i].bt;
    		p[i].ct=time;
	    	gant[g++]=p[i];
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		twt=twt+p[i].wt;
		tat=tat+p[i].tt;
	}
	printf("Gantt chart:\n");
	for(i=0;i<g;i++)
	{
		if(gant[i].bt==0)
			printf("| Idle   ");
		else
			printf("| p%d\t",gant[i].no);
	}
	printf("|\n");
	printf("0\t");  
	for(i=0;i<g;i++)
		printf("%d\t",gant[i].ct);
	printf("\nTable :\n");
	printf(" _____________________________________________________\n");
	printf("|Process| AT\t| BT\t| P \t| CT\t| TT\t| WT\t|\n");
	printf("|----------------------------------------------------|\n");
	for(i=0;i<n;i++)
	{
		printf("|p%d \t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t|\n",p[i].no,p[i].at,p[i].bt,p[i].p,p[i].ct,p[i].tt,p[i].wt);
	}
	printf(" ___________________________________________________\n");
	twt=twt/n;
	tat=tat/n;
	printf("\nAverage WT:%f\n",twt);	
	printf("Average TT:%f\n",tat);		
}