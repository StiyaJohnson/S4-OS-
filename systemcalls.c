#include<stdio.h>
#include<unistd.h>

void main()
{
    int a,p;
    a=fork();
    if(a<0)
    {
        printf("error\n");
    }
    else if(a==0)
    {
        p=getpid();
        printf("child process id:%d\n",p);
    }
    else
    {
        printf("parent id:%d\n",getpid());
    }
}