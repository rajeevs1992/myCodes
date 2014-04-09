#include<stdio.h>
int main()
{
    char array[125000000];
    unsigned long long int i,j,p=2;
    for(i=2;i<100000001/p;i++)
    {
        array[p*i]=1;
    }
    return 0;
}
