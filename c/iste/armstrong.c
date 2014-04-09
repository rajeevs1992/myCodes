#include<stdio.h>
int main()
{
    int n,f=1,t,i,sum=0;
    printf("Enter number ");
    scanf("%d",&n);
    t=n;
    while(t)
    {
        i=t%10;
        sum+=i*i*i;
        t=t/10;
    }
    if(n==sum)
        printf("Armstrong\n");
    else
        printf("Not Armstrong\n");
}
