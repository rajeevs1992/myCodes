#include<stdio.h>
int max_claim[10][10];
int allocated[10][10];
int max[10];
int main()
{
    int p,r,i,j,k,f;
    scanf("%d",&p);
    scanf("%d",&r);
    for(i=0;i<r;i++)
    {
        scanf("%d",&max[i]);
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max_claim[i][j]);
            scanf("%d",&allocated[i][j]);
            max[j] -= allocated[i][j];
        }
        allocated[i][j]=0;
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            f=0;
            if(allocated[j][r]!=1) 
            {
                for(k=0;k<r;k++)
                {
                    if(max[k]<max_claim[j][k]-allocated[j][k])
                    {
                        f=1;
                        break;
                        //process cannot complete,insufficient resources
                    }
                }
                if(f==0)
                {
                    //process can complete
                    for(k=0;k<r;k++)
                    {
                   //     printf("%d ",max[k]);
                        max[k] += allocated[j][k];
                    }
                    allocated[j][r]=1;
                }
            }
        }
    }
    f=1;
    for(i=0;i<p;i++)
    {
        if(allocated[i][r]==0)
        {
            f=0;
            break;
        }
    }
    if(f==0)
        printf("Unsafe\n");
    else
        printf("Safe\n");
    return 0;
}

