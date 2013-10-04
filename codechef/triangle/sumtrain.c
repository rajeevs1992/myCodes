#include<stdio.h>
#include<limits.h>
int main()
{
    int n,limit,i,j,k,l,sum=0;
    long int array[100][100],min;
    long int array2[100][100];
    n=1;
        scanf("%d",&limit);
        for(j=0;j<limit;j++)
            for(k=0;k<=j;k++)
            {
                scanf("%ld",&array[j][k]);
                array2[j][k]=array[j][k];
            }
        for(i=0;i<limit;i++)
        {   
            for(j=0;j<=i;j++)
            {
                //a[i][j]
//                printf("Current head %d\n",array[i][j]);
                min=array[i][j];
                sum=min;
                for(k=i+1;k<limit;k++)
                {
                    for(l=j;l<=j+k-i;l++)
                    {
  //                      printf("%d ",array[k][l]);
                        sum+=array[k][l];
                    }
                    if(sum<min)
                        min=sum;
    //                printf("\n");
                }
                array2[i][j]=min;
            }
        }
    min=array2[0][0];
//    printf("\n");
    for(i=0;i<limit;i++)
    {
        for(j=0;j<=i;j++)
        {
  //          printf("%ld ",array2[i][j]);
            if(array2[i][j]<min)
                min=array2[i][j];
        }
//    printf("\n");
    }
    printf("%ld\n",min);
    return 0;
}
