#include<stdio.h>
int main()
{
    int n,f=0,t,i;
    printf("Enter number ");
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
        if(n%i == 0)
        {
            f=1;
            break;
        }
    if(f==1)
        printf("Not Prime\n");
    else
        printf("Prime\n");

}
