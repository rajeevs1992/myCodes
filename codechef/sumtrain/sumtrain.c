#include<stdio.h>
int main()
{
    int n,limit,i,j,t,k,sum;
    int array[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&limit);
        for(j=0;j<limit;j++)
        {
            for(k=0;k<=j;k++)
                scanf("%d",&array[j][k]);
        }
        for(j=limit-1;j>=0;j--)
        {
            for(k=0;k<j;k++)
            {
                if(array[j][k]>array[j][k+1])
                    array[j-1][k] = array[j-1][k] + array[j][k];
                else
                    array[j-1][k] = array[j-1][k] + array[j][k+1];
            }
        }
        printf("%d\n",array[0][0]);
    }
    return 0;
}
