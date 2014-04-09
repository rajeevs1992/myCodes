#include<stdio.h>
int main()
{
    int c1,c2,i;
    unsigned long long int a,b,parents[31],n;
    scanf("%llu",&n);
    while(n--)
    {
        c1=0;
        c2=0;
        scanf("%lld%lld", &a, &b);
        parents[c1++]=a;
        while(a!=1)
        {
            a=(a)/2;
            parents[c1++]=a;
        }
        while(1)
        {
            for(i=0;i<c1;i++)
                if(parents[i] == b || parents[i]<b)
                    break;
            if(parents[i] == b)
            {
                printf("%d\n",i+c2);
                break;
            }
            b=b/2;
            c2++;
        }
    }
    return 0;

}
