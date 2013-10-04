#include<stdio.h>
int fact(int n)
{
    int f=1;
    n++;
    while(--n)
        f=f*n;
 //   printf("%d\n",f);
    return f;
}
int main()
{
    int n,c=0,x=0,y,t;
    scanf("%d",&n);
    while(1)
    {
        y=n-(2*x);
//        printf("%d--%d\n",x,y);
        if(y<0)
            break;
        t=fact(x+y)/(fact(x)*fact(y));
 //       printf("%d",t);
        c+=t;

        x++;
    }
    printf("%d\n",c);
}
