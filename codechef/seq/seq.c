#include<stdio.h>
#include<math.h>
int guesspow(unsigned long long int array[100])
{
    int i,j=1,p;
    if(array[1] == 0)
        return 0;
    for(i=0;i<100;i++)
        if(array[j] == powl(j+1,i))
            return i;
    return 0;
}
int main()
{
    int m,n,i,p;
    unsigned long long int array[100]={0};
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=0;i<m;i++)
        scanf("%lld",&array[i]);
    p=guesspow(array);
    for(i=m+1;i<=m+n;i++)
        printf("%.0Lf ",powl(i,p));
    printf("\n");
    return 0;
}
