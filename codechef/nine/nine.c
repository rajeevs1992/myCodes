#include<stdio.h>
int main()
{
    int t,n,flag;
    unsigned long long int a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=1;
        b=10;
        flag=0;
        while(flag==0)
        {
            while(a!=b)
            {
                if(n%(a-b) == 0)
                {
                    printf("%llu\n",a-b);
                    flag=1;
                    break;
                }
                else
                    a=a*10;
            }
            b=b*10;
        }
    }
}
