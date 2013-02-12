#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int a;
main()
{
    for(a=0;a<5;a++)
    {
        if(fork()==0)
        {
            printf("%d\n",a);
            _exit(0);
        }
    }
}
