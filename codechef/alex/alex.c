#include<stdio.h>
int main()
{
    int t,c,n,i,j;
    unsigned long long int a;
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%llu",&a);
        a=n;
        printf("%llu\n",a*(a-1)/2);
    }
    return 0;

}

