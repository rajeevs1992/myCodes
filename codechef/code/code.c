#include<stdio.h>
int main()
{
    int y[1000000];
    int t,n,k,i,j,array[1000],a,b;
    long long int ans;
    char opr[4]={0};
    scanf("%d",&t);
    for(a=0;a<t;a++)
    {
        scanf("%d",&n);
        scanf("%d",&k);
        scanf("%lld",&ans);
        for(b=0;b<n;b++)
            scanf("%d",&array[b]);
        scanf("%s",opr);
        if(opr[0]=='X')
        {
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ans==0)
            {
                ans=array[j];
                continue;
            }
            ans=(ans ^ array[j]);
        }

    }
    printf("%lld\n",ans);
        }
    else if(opr[0]=='O')
    {
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
                ans=(ans | array[j]);
    }
    printf("%lld\n",ans);
    }
    else
    {
    for(i=0;i<k;i++)
    {
        if(ans==0)
            break;
        for(j=0;j<n;j++)
            if(ans==0)
                break;
            else
                ans=(ans & array[j]);
    }

    printf("%lld\n",ans);
    }
    }
}
