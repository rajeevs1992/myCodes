#include<stdio.h>
#include<math.h>
typedef unsigned long long int uli;
int check(uli f)
{
    int flag=1,t,c=0,i;
    t=sqrt(f);
    for(i=1;i<t;i++)
        if(f%i ==0)
            c+=2;
    if(f%t==0)
        c++;
    printf("%d %llu\n",c,f);
    int l=ceil(sqrt(c));
    if(c==1||c==0)
        return 0;
    for(t=2;t<=l;t++)
        if(c%t == 0)
            return 0;
    return 1;
}
int main()
{
    int t,c,limit;
    uli a,b,i;
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%llu%llu",&a,&b);
        for(i=a;i<=b;i++)
            if(check(i))
            {
                printf("%llu\n",i);
                c++;
            }
        printf("%d\n",c);
    }
    
    return 0;
}
