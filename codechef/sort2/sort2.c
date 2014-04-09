#include<stdio.h>
int main()
{
    int array[100],n,i,f,l,t;
    scanf("%d",&n);
    f=0;
    l=n-1;
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    while(f<l)
    {
        while(array[f] == 0)
            f++;
        while(array[l] == 1)
            l--;
        if(f<l)
        {
            t = array[f];
            array[f] = array[l];
            array[l] = t;
        }
        f++;
        l--;
    }
    for(i=0;i<n;i++)
        printf("%d\n",array[i]);
}
