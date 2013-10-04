#include<stdio.h>
int has_7(int c)
{
    while(c)
    {
        if(c%10==7) 
            return 1;
        c=c/10;
    }
    return 0;
}
int main()
{
    int n,p,i=0,adder=1,c=1;
    scanf("%d",&n);
    scanf("%d",&p);
    while(1)
    {
        i = i+adder;
        if(i==n+1)
            i=1;
        else if(i==0)
            i=n;
        if(c==p)
        {
            printf("%d\n",i);
            break;
        }
        if(c%7 == 0 || has_7(c))
        {
            adder = adder*-1;
        }
//        printf("%d\t",i);
        c++;
    }
}

