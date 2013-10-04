#include<stdio.h>
int main()
{
    unsigned long long int n,m,t;
    scanf("%lld",&t);
    while(t--)
    {
    scanf("%lld",&n);
    scanf("%lld",&m);
    if(m==1)
        printf("%lld\n",n);
    else if(n==1)
        printf("%lld\n",m);
    else if(m==n)
        printf("%lld\n",m);
    else
        printf("2\n");
    }
        
}
