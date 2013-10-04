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
int main()
{
    int n,i,j;
    unsigned long long int array[100000][2],s1,s2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&array[i][0]);
        scanf("%llu",&array[i][1]);
        qsort(&array,i+1,sizeof(array[0]),compare);
        s1=s2=0;
        for(j=0;j<i+1;j++)
        {
            if(j<=(i)/2)
                s1+=array[j][1];
            else
                s2+=array[j][1];
        }
        if(s1>s2)
            printf("%llu\n",s1-s2);
        else
            printf("%llu\n",s2-s1);
    }
    return 0;

}
