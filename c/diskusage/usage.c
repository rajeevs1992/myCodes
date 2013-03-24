#include<stdio.h>
#include<sys/statfs.h>
int main()
{
    struct statfs *stat;
    if(!statfs("/",stat))
        printf("Error");
    else
    {
        printf("%lu \n",stat->f_bfree);
        printf("%lu \n",stat->f_blocks);
    }
    return 0;
}
