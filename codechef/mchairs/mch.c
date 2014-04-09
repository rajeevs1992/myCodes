#include<stdio.h>
int main()
{
    unsigned long long int n,temp,x,pow;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        pow=2;
        x=1;
        while(n)
        {
            if(n&1)
                x=(x*pow)%1000000007;
            pow=(pow*pow)%1000000007;
            n=n>>1;
        }
        printf("%llu\n",x-1);
    }
    return 0;
}
