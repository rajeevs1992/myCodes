#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int l,d,s,c;
    double ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu%llu%llu",&l,&d,&s,&c);
        ans=log(s)+((d-1)*log(1+c));
        printf("%f\n%f\n",ans,log(l));

        if(ans>=log(l))
            printf("ALIVE AND KICKING\n");
        else
            printf("DEAD AND ROTTING\n");
    }
    return 0;
}
