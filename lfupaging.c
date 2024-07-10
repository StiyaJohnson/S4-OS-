#include <stdio.h>
void main()
{
	int i,j,n,a[50],f,freq[10],frame[10],min,miss=0,loc,flag=0,time[10],find;
	printf("enter the length of refence string;");
	scanf("%d",&n);
	printf("enter the reference string:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the frame size;");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		frame[i]=-1;
		freq[i]=0;
		time[i]=0;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<f;j++)
		{
			if(a[i]==frame[j])
			{
				flag=1;
				freq[j]++;
				time[j]++;
				break;
			}
		}
		if(flag==0)
		{
			miss++;
			if(i<f)
			{
				frame[i]=a[i];
				freq[i]=1;
				time[i]++;
			}
			else
			{
				loc=0;
				min=freq[0];
				find=0;
				for(j=1;j<f;j++)
				{
					if(freq[j]<min)
					{
						min=freq[j];
						loc=j;
					}
					else if(freq[j]==min&&time[j]<time[loc])
					{
						loc=j;
					}
				}
				frame[loc]=a[i];
				freq[loc]=1;
				time[loc]++;
			}
		}
		printf("frame:");
		for(j=0;j<f;j++)
		{
			printf("%d\t",frame[j]);
		}
		printf("\n");
		
	}
	printf("page fragmentation=%d",miss);
}
				
			