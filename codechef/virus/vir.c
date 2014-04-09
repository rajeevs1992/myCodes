#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,lV,lP,mismatch,diff;
    char P[100000],V[100000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",P,V);
        lV=strlen(V);
        lP=strlen(P);
        diff = lP-lV+1;

        for(i=0;i<diff;i++)
        {
            mismatch=0;
            for(j=0;j<lV;j++)
            {
                if(P[i+j]!=V[j])
                    mismatch=mismatch+1;
                if(mismatch>1)
                    break;
            }
            if(mismatch <=1)
                printf("%d ",i);
        }
        printf("\n",i);
    }
    return 0;
    
}
