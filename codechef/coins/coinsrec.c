#include<stdio.h>
typedef long long int uli;
uli breakup(uli n);
uli max[10000000] = {0};
int main()
{
    uli n;
    int i;
    while(scanf("%lld",&n) != EOF)
    {
        printf("%lld\n",breakup(n));
    }
}
uli breakup(uli n)
{
    int i;
    if(n == 1)
        return 1;
    if(n < 1)
        return 0;
    if(n<10000000 && max[n] != 0)
        return max[n];

    uli n1,n2,n3,t;
    n1 = n/2;
    n2 = n/3;
    n3 = n/4;
    t = breakup(n1);
    if(t>n1)
        n1 = t;
    t = breakup(n2);
    if(t>n2)
        n2 = t;
    t = breakup(n3);
    if(t>n3)
        n3 = t;
    t = n1+n2+n3;
    if(t>n)
    {
        if(n<10000000)
            max[n] = t;
        return t;
    }
    else
    {
        if(n<10000000)
            max[n] = n;
        return n;
    }
}
