#include<stdio.h>
int main()
{
    unsigned long long int b,temp,x,res,pow,t;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&b);
        temp=b;
        pow=1;
        res=0;
        while(temp)
        {
            res=res+((temp&1)*pow);
            temp=temp>>1;
            pow=pow*10;
        }
//        printf("%llu\n",res);
        temp=res;
        x=1;
        pow=4;
        while(temp>0)
        {
            if(temp&1)
                x=(x*pow) % 1000000007;
            pow=(pow*pow) % 1000000007;
            temp=temp>>1;
        }
        printf("%llu\n",x);
    }
    return 0;
}
