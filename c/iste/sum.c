#include<stdio.h>
int main()
{
    int n,a,t,i;
    float sum=0;
    printf("Enter limit ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
    }
    printf("Sum %.2f\nAverage %.2f\n",sum,sum/n);
}    
