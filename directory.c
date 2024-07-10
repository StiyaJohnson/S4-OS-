#include<stdio.h>
#include<dirent.h>

void main()
{
    DIR *dir=opendir(".");
    struct dirent *entry;
    while((entry=readdir(dir))!=NULL)
    {
        if(entry->d_type == DT_REG)
        {
            if(entry->d_name[0]=='l')
            {
                printf("%s\n",entry->d_name);
            }
        }
    }
}