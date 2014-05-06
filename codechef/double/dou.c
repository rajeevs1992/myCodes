#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    long long int n;
    while(t--)
    {
        scanf("%lld",&n);
        if(n&1)
            printf("%lld\n",n-1);
        else
            printf("%lld\n",n);
    }
    return 0;
}
