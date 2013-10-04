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
    int n,k,i,j,count=0,array[100000];
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    qsort(array,n,sizeof(n),compare);
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(array[j]-array[i] == k)
                count++;
    printf("%d\n",count);
    return 0;
}
