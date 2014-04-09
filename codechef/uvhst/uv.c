#include<stdio.h>
int main()
{
    int t;
    unsigned long long int n,c,no;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu",&n,&c);
        no=ceil(n/(float)c);
        printf("%llu\n",no-1);
    }
    return 0;

}

