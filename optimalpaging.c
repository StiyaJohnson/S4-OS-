#include<stdio.h>
void main()
{
	int i,j,page[20],frame[10],c[10],p,f,flag,k,miss=0,max,find;
	printf("enter the length of reference string:");
	scanf("%d",&p);
	printf("enter the refernce sring;");
	for(i=0;i<p;i++)
	{
		scanf("%d",&page[i]);
	}
	printf("enter the number of frames;");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		frame[i]=-1;
	}
	for(i=0;i<p;i++)
	{
		flag=0;
		for(j=0;j<f;j++)
		{
			if(frame[j]==page[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			if(i<f)
			{
				frame[i]=page[i];
			}
			else
			{
				for(j=0;j<f;j++)
				{
					find=0;
					for(k=i;k<p;k++)
					{
						if(frame[j]==page[k])
						{
							c[j]=k;
							find=1;
							break;
						}
					}
					if(find==0)
					{
						c[j]=1000;
					}
				}
				max=0;
				for(j=1;j<f;j++)
				{
					if(c[j]>c[max])
					{
						max=j;
					}
				}	
				frame[max]=page[i];
			}
			miss++;
		}
		printf("current frame:");
		for(j=0;j<f;j++)
		{
			printf("%d\t",frame[j]);
		}
		printf("\n");
	}
	printf("page fault=%d",miss);
}
		