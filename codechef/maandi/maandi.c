#include<stdio.h>
#include<math.h>
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
    int t,c,limit,i;
    uli n;
    scanf("%d",&t);
    while(t--)
    {
        char array[1000000]={0};
        c=0;
        scanf("%llu",&n);
        limit=sqrt(n);
            for(i=1;i<=limit;i++)
            {
                if(n%i==0)
                {
                    if(check(i))
                    {
                        c++;
                    }
                  if(check(n/i))
                    {
                        c++;
                    }
                }
            }
        printf("%d\n",c);
    }
    
    return 0;
}
