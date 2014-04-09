#include<stdio.h>
int main()
{
    int t,n,c,m,count,wrapper,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&c,&m);
        count=wrapper=n/c;
        while(wrapper>=m)
        {
            temp=wrapper/m;
            count+=temp;
            wrapper=wrapper%m;
            wrapper+=temp;
        }
        printf("%d\n",count);
    }
    return 0;
}
