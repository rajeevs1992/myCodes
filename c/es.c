#include<stdio.h>
int main()
{
    int lt,sum=0,i,n;
    scanf("%d",&lt);
    for(i=0;i<lt;i++)
    {
        scanf("%d",&n);
        sum=add(n,sum);
    }
    printf("%d",sum);
    return 0;
}

int add(int a,int sum)
{
    int i,c=0,t=0,bit1,bit2,xor;
    for(i=0;i<32;i++)
    {
        bit1=a>>i&1;
        bit2=sum>>i&1;
        xor=bit1^bit2^c;
        t=t|xor<<i;
        if(bit1==1 && bit2==1)
            c=1;
        else
            c=0;
    }
    t=t|c<<31;
    return t;
}
