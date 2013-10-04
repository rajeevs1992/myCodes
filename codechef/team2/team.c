#include<stdio.h>
int compare(const void* a, const void* b)
{
    
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    if(*ia>*ib)
        return 1;
    else if(*ia==*ib)
        return 0;
    else
        return -1;
}
int compare2(const void* a, const void* b)
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
int main()
{
    int n,i,j,s1,s2,array[100],array1[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
        array1[i]=array[i];
        qsort(&array,i+1,sizeof(array[0]),compare);
        qsort(&array1,i+1,sizeof(array[0]),compare2);
        s1=s2=0;
        for(j=0;j<(i+1)/2;j++)
        {
            if((i+1)/2<=1)
            {
                s1=array[0];
                s2=array1[0];
            }
            else if(j%2 == 0)
                s1=array[j]+array1[j];
            else
                s2=array[j]+array1[j];
        }
        if((i+1)%2!=0)
        {
        if(s1<s2)
            s1+=array[(i+1)/2];
        else
            s2+=array[(i+1)/2];
        }
        if(s1>s2)
            printf("%d\n",s1-s2);
        else
            printf("%d\n",s2-s1);
    }
    return 0;

}
