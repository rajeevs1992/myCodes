#include<stdio.h>
#include<math.h>
int main()
{
    int n,c;
    unsigned long long int a,b,i,s;
    unsigned long long int ra,rb;
    scanf("%d",&n);
    while(n--)
    {
        c=0;
        scanf("%llu%llu",&a,&b);
        ra = ceil(sqrt(a));
        rb = floor(sqrt(b));
        printf("%llu\n",rb-ra+1);
    }
    return 0;
}
