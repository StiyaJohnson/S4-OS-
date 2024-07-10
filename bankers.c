#include<stdio.h>
void main()
{
    int max[10][10],allocated[10][10],available[10],req[10],need[10][10],safety[10],finish[10],i,j,k,n,m,p,count=0;
    printf("Enter the no of processors\n");
    scanf("%d",&n);
    printf("Enter the no of resources\n");
    scanf("%d",&m);
    printf("Enter the allocated matrix\n");
    for(i=0;i<n;i++)
    {
        finish[i]=0;
        printf("Process %d",i);
         printf("\n");
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
     printf("\nEnter the max matrix\n");
    for(i=0;i<n;i++)
    {
        
        printf("Process %d",i);
        printf("\n");
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
     printf("\nEnter the available matrix\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }

        //finding need matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }

    printf("__________________________Resource allocation table__________________________________\n");
    printf("Process\tAllocated\tMax\tAvailable\tNeed\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t",i);
        for(j=0;j<m;j++)
        {
            printf("%d ",allocated[i][j]);
        }
        printf("\t\t");
        for(j=0;j<m;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\t\t");
        if(i==0)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",available[j]);
            }
        }
        printf("\t\t");
       

        for(j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
        
       
    }

    printf("Enter the requesting process\n");
    scanf("%d",&p);
    printf("Enter the requesting sequence\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&req[i]);
    }

    int f=0;
    for(i=0;i<m;i++)
    {
        if(req[i]>need[p][i] && req[i]>available[i])
        {
            f=1;
            break;
        }
    }

    if(f==0)
    {
        printf("Request status successfull\n");
        for(j=0;j<m;j++)
        {
            allocated[p][j]=allocated[p][j]+req[j];
            need[p][j]=need[p][j]-req[j];
            available[j]=available[j]-req[j];

        }

        printf("_______________________The Modified Resource Allocation Table is_____________________\n");
         printf("Process\tAllocated\tMax\t\tAvailable\tNeed\n");
        for(i=0;i<n;i++)
      {
        printf("P%d\t",i);
        for(j=0;j<m;j++)
        {
            printf("%d",allocated[i][j]);
        }
        printf("\t\t");
        for(j=0;j<m;j++)
        {
            printf("%d",max[i][j]);
        }
            printf("\t\t");
        if(i==0)
        {
            for(j=0;j<m;j++)
            {
                printf("%d",available[j]);
            }
        }
        printf("\t\t");
       
        for(j=0;j<m;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
        
        
      }

      int c=0;
      int flag=0;
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {
            if(finish[j]==0)
            {
                for(k=0;k<m;k++)
                {
                    if(available[k]<need[j][k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("P%d : executed\n",j);
                    safety[c]=j;
                    c++;
                    finish[j]=1;
                    count++;
                    printf("Available :\n");
                    for(k=0;k<m;k++)
                    {
                        available[k]=available[k]+allocated[j][k];
                        printf("%d ",available[k]);
                    }

                }
            }
            flag=0;
        }
      }

      if(count==n)
      {
        printf("Deadlock free-____________\n");
        printf("Safety sequence\n");
        printf(" P%d ",safety[0]);
        for(i=1;i<c;i++)
        {
            printf("->P%d",safety[i]);
        }
      }
      else
      {
            printf("Deadlock condition\n");
      }

    }

    else
    {
        printf("\nrequest status :fail\n");
    }
    

}