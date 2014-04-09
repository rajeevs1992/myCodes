#include<stdio.h>
int main()
{
    int n,f=1,t,i;
    printf("Enter limit ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        f=f*i;
    printf("%d\n",f);
}
