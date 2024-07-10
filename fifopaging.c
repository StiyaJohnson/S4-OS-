#include<stdio.h>
int option,n,frames,i,j,c,a[100],choice,count[100],inframe[100],array[100],miss=0;
void fifo(int a[],int n,int frames);
void main()
{
    printf("Enter the no: of reference strings:\n");
    scanf("%d",&n);
    printf("Enter the no: of frames\n");
    scanf("%d",&frames);
    printf("Enter the reference string\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
   {
        for(i=0;i<n;i++)
        {
            count[a[i]]=0;
            inframe[a[i]]=0;
        }
        printf("1:FIFO\n");
        printf("press 1 for FIFO\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:fifo(a,n,frames);
                    break;
        }
        printf("\nDo u want to continue...if yess pres 2 to contine\n");
        scanf("%d",&choice);

   }while(choice==2);
    

}

void fifo(int a[],int n,int frames)
{
    int inframe[100],miss=0,c=0;
    for(i=0;i<n;i++)
    {
        if(inframe[a[i]]==0)
        {
            if(c<frames)
            {
                array[c++]=a[i];
            }
            else
            {
                inframe[a[i]]=0;
                array[j]=a[i];
                j=(j+1)%frames;
            }

            inframe[a[i]]=1;
            miss++;
        }
    }
    printf("The page faults :%d\n",miss);
}