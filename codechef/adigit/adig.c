#include<stdio.h>
#define ADD(prev,a,c) prev+(a>c?a-c:c-a)
int main()
{
    int m,n,x,b;
    int i;
    char a[100000];
    long long int b0[100000];
    long long int b1[100000];
    long long int b2[100000];
    long long int b3[100000];
    long long int b4[100000];
    long long int b5[100000];
    long long int b6[100000];
    long long int b7[100000];
    long long int b8[100000];
    long long int b9[100000];
    scanf("%d%d%s",&m,&n,a);
    i=0;
        m--;
        b=a[i] - '0';
        b0[0]=ADD(0,b,0);
        b1[0]=ADD(0,b,1);
        b2[0]=ADD(0,b,2);
        b3[0]=ADD(0,b,3);
        b4[0]=ADD(0,b,4);
        b5[0]=ADD(0,b,5);
        b6[0]=ADD(0,b,6);
        b7[0]=ADD(0,b,7);
        b8[0]=ADD(0,b,8);
        b9[0]=ADD(0,b,9);
        i++;
    while(m--)
    {
        b=a[i]-'0';
        b0[i]=ADD(b0[i-1],b,0);
        b1[i]=ADD(b1[i-1],b,1);
        b2[i]=ADD(b2[i-1],b,2);
        b3[i]=ADD(b3[i-1],b,3);
        b4[i]=ADD(b4[i-1],b,4);
        b5[i]=ADD(b5[i-1],b,5);
        b6[i]=ADD(b6[i-1],b,6);
        b7[i]=ADD(b7[i-1],b,7);
        b8[i]=ADD(b8[i-1],b,8);
        b9[i]=ADD(b9[i-1],b,9);
        i++;
    }
    while(n--)
    {
        scanf("%d",&x);
        x--;
        i=a[x]-'0';
        switch(i)
        {
            case 0:printf("%lld\n",b0[x]);break;
            case 1:printf("%lld\n",b1[x]);break;
            case 2:printf("%lld\n",b2[x]);break;
            case 3:printf("%lld\n",b3[x]);break;
            case 4:printf("%lld\n",b4[x]);break;
            case 5:printf("%lld\n",b5[x]);break;
            case 6:printf("%lld\n",b6[x]);break;
            case 7:printf("%lld\n",b7[x]);break;
            case 8:printf("%lld\n",b8[x]);break;
            case 9:printf("%lld\n",b9[x]);break;
        }
    }
    return 0;
}
