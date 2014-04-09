#include<stdio.h>
int main()
{
    int n, arr[10]={0},t,i,j=1,num=0;
    scanf("%d",&n);
    t=n;
        for(i=9;i>1;i--)
        {
            while(t%i == 0)
            {
                num = (j*i)+num;
                t=t/i;
                j=j*10;
            }
        }
        if(t == 1)
            printf("%d\n",num);
        else
            printf("-1\n");
            
}
