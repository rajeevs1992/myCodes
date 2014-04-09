#include<stdio.h>
int main()
{
    int n,a=0,b=1,t,i;
    printf("Enter limit ");
    scanf("%d",&n);
    printf("0 1 ");
    for(i=0;i<n-2;i++)
    {
        t=a+b;
        printf("%d ",t);
        a=b;
        b=t;
    }
    printf("\n");
}
