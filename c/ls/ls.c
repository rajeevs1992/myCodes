#include<dirent.h>
#include<stdio.h>
#include<malloc.h>
int main(int argc,char *argv[])
{
struct dirent *res;
DIR *dir;
char str[100];
scanf("%s",str);
    dir=(DIR *)opendir(str);
    if(dir==NULL)
    {
        perror("Invalid directory");
        return 1;
    }
    res=(struct dirent *)readdir(dir);
    while(res)
    {
        printf("%s\n",res->d_name);
        res=(struct dirent *)readdir(dir);
    }
    return 0;
}

