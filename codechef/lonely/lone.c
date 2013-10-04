#include<stdio.h>
int main()
{
    int n,i,k=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        k = k^t;
    }
    printf("%d\n",k);
    return 0;
}
