#include<stdio.h>
int main()
{
    double area,max=0,min=0;
    int n,ax,bx,cx,ay,by,cy,f=1,ind1,ind2,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
        area=((ax*(by-cy))+(bx*(cy-ay))+(cx*(ay-by)))/2;
        if(area<0)
            area=area*-1;
        if(f==1)
        {
            max=min=area;
            f=0;
            ind1=ind2=1;
        }
        if(area>=max)
        {
            max=area;
            ind1=i+1;
        }
        if(area<=min)
        {
            min=area;
            ind2=i+1;
        }
 //       printf("%f\n",area);
    }
    printf("%d %d\n",ind2,ind1);
    return 0;
}
