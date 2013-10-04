#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
    
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    if(*ia>*ib)
        return -1;
    else if(*ia==*ib)
        return 0;
    else
        return 1;
}
int fact(int a)
{
    int f=1;
    if(a==0)
        return 1;
    while(a>0)
        f=f*a--;
    return f;
}
int main()
{
    int t,n,sum=0,array[11],i,ans=0,c,e,j,temp;
    scanf("%d",&t);
    while(t--)
    {
        int hash[101]={0};
        ans=1;
        c=1;
        for(i=0;i<11;i++)
        {
            scanf("%d",&array[i]);
            hash[array[i]]++;
        }
        qsort(&array,11,sizeof(array[0]),compare);
        scanf("%d",&n);
        e=array[n-1];
        j=n-1;
        while(array[j]==array[j-1] && j>0)
        {
            c++;
            j--;
        }
        temp=hash[e];
        for(i=1;i<=c;i++)
            ans=ans*temp--;
        ans=ans/fact(c);
        printf("%d\n",ans);
    }
    return 0;
}
