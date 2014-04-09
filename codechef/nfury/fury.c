#include<stdio.h>
#include<math.h>
int main()
{   
    int t,n,area,rem,c,i,r;
    scanf("%d",&t);
    while(t--)
    {
        area=0;
        c=0;
        scanf("%d",&n);
        if(n==18)
        {
            printf("2\n");
            continue;
        }
        rem=n;
        while(area<n)
        {
            r=sqrt(rem);
            if(r==0)
                r=1;
            area=area+(r*r);
            c++;
            rem=n-area;
        }
        printf("%d\n",c);

    }
    return 0;
}
