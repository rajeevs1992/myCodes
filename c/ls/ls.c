#include<dirent.h>
#include<stdio.h>
#include<malloc.h>
int main(int argc,char *argv[])
{
struct dirent *res;
struct DIR *dir;
char str[100];
scanf("%s",str);
    dir=opendir(str);
    if(dir==NULL)
    {
        perror("Invalid directory");
        return 1;
    }
    res=readdir(&dir);
    while(res)
    {
        printf("%s\n",res->d_name);
        res=readdir(&dir);
    }
    return 0;
}

