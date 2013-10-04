#include<stdio.h>
#include<stdlib.h>
int compare (const void * elem1, const void * elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main()
{
    int limit,pies[30],racks[30],n,i,j,k,count;
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        count = 0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&pies[j]);
        for(j=0;j<n;j++)
            scanf("%d",&racks[j]);
        qsort(pies,n,sizeof(n),compare);
        qsort(racks,n,sizeof(n),compare);
        j=k=0;
        while(j<n && k<n)
        {
            if(pies[j] <= racks[k])
            {
                count++;
                j++;
                k++;
            }
            else
            {
                k++;
            }
        }
        printf("%d\n",count);
        
    }
    return 0;

}
