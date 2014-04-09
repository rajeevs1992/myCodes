#include<stdio.h>
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int n,a=0,b=1,t,i;
    printf("Enter limit ");
    scanf("%d",&n);
    printf("%d\n",fact(n));
}
