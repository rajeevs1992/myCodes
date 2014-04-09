#include<stdio.h>
int main()
{
    unsigned long long int m,n,x,y,i,j;
    long long int B1,B2,b;
    char a[100000];
    scanf("%llu%llu%s",&m,&n,a);
    while(n--)
    {
        i=j=0;
        B1=B2=0;
        scanf("%llu",&x);
        x--;
        while(i<=x)
        {
 //           printf("%c %c %llu\n",a[i],a[x],x);
            b = a[x]  - a[i];
            i++;
            if(b<0)
                B1 += -1*b;
            else
                B1 += b;
        }
        printf("%lld\n",B1);
    }
    return 0;
}
