#include<stdio.h>
#include<math.h>
int ifspecial(unsigned long long int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    unsigned long long int root,i;
    int f=0;
    root=ceil(sqrt(n));
    for(i=2;i<=root;i++)
    {
        if(n%i == 0 && i!=root)
        {
            
            return 0;
        }
    }
    return 1;

}
int main()
{
    int t,flag,c;
    unsigned long long int l,r,i,root1,root2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu",&l,&r);
        c=0;
        for(i=l;i<=r;i++)
            if(ifspecial(i))
            {
                c++;
            }
        printf("%d\n",c);
   }
}
