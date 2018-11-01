#include<stdio.h>

int main()
{
    int n,p1,p2,k,s;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d%d", &p1,&p2,&k);
        s = (p1+p2)/k;
        if(s % 2 == 0)
        {
            printf("CHEF\n");
        }
        else
        {
            printf("COOK\n");
        }
    }
    return 0;
}
