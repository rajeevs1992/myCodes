#include<stdio.h>
int main()
{
    int n,k,t,i,c;
    unsigned long long int array[101];
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%llu",&array[i]);
        scanf("%d",&k);
        for(i=0;i<n;i++)
            if(array[i]<array[k-1])
                c++;
        printf("%d\n",c+1);
    }
    return 0;
}
