#include<stdio.h>
#include<string.h>
unsigned long long int array[10000000]={0};
unsigned long long int fact(long int a)
{
    unsigned long long int f;
    if(a==0||a==1)
        return 1;
    if(a<10000000 && array[a]!=0)
        return array[a];
    else
    {
        f=a*fact(a-1);
        if(a<10000000)
            array[a]=f;
        return f;
    }
}
int main()
{
    long int k,n,t,temp,i;
    unsigned long long int ans=1;
    scanf("%ld",&t);
    while(t--)
    {
        ans = 1;
        scanf("%ld",&n);
        scanf("%ld",&k);
        if(k>n)
        {
            printf("1\n");
            continue;
        }
        if(n-k < k)
            k=n-k;
        temp=n;

        for(i=1;i<=k;i++)
            ans=ans*temp--;
        ans=ans/fact(k);
        printf("%llu\n",ans);
    }
    return 0;
}
