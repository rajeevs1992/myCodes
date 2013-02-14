#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int a;
main()
{
    char c[]={"hello"};
    char *d=c;
    c=c+1;
    puts(c);
}
