#include<stdio.h>
typedef unsigned long long int uli;
int check(uli f)
{
    int flag=1,t;
    while(f)
    {
        t=f%10;
        if(t==4 || t==7)
            return 1;
        f=f/10;
    }
    return 0;
}
int main()
{
    int t,c,init,i;
    uli n;
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%llu",&n);
            for(i=2;i<=n;i++)
            {
                if(n%i==0)
                {
                    printf("%d ",i);
                    if(check(i))
                    {
                        c++;
                    }
                }
            }
        printf("%d\n",c);
    }
    
    return 0;
}
