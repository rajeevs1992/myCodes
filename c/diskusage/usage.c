#include<stdio.h>
#include<sys/statfs.h>
int main()
{
    struct statfs stat;
    statfs("/",&stat);
    perror("");
    printf("%lu \n",stat.f_bfree*stat.f_bsize);
    return 0;
}
