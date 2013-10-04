#include<stdio.h>
int countones(int num)
{
    int c=0,n=num;

    while(n)
    {
        if(n&1)
            c++;
        n=n>>1;
    }
//    printf("Ones in %d is %d \n",num,c);
    return c;
}
int main()
{
    int n,i,j,player=1,t,ones_n,ones_d;
    scanf("%d",&n);
    while(1)
    {
        if(player==0)
            player=1;
        else
            player=0;
        i=n;
        while(i)
        {
            ones_n=countones(n);
            i=i-1;
            if(countones(i)<=ones_n)
            {
//                printf("N %d Player %d D %d\n",n,player,i);
                n=n-i;
                break;
            }
        }
        if(i==0)
            break;
    }
    if(player==1)
        printf("Holmes\n");
    else
        printf("Watson\n");
    return 0;
}
