#include<dirent.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
struct dirent *res;
struct DIR *dir;

    if(argc=='1')
    {
        write(2,"Usage: ./ls <Directory name>",40);
        return 1;
    }

    dir=opendir(argv[1]);
    if(dir==NULL)
    {
        perror("Invalid directory");
        return 1;
    }
    res=readdir(dir);
    while(res)
    {
        printf("%s\n",res->d_name);
        res=readdir(dir);
    }
    return 0;
}

