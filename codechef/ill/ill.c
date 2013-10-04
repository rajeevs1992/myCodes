#include<stdio.h>
int array[100][100],count[100][2],queue[100]={0};
int in(int n,int t)
{
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(count[i][1]==1)
                break;
            else if(array[i][j]==t)
                return i;
        }
    return -1;
}
void q_sick(int s)
{
}
int main()
{
    int m,n,i,j,p,t,c=0;
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p);
        count[i][0]=p;
        count[i][1]=0;
        for(j=0;j<p;j++)
            scanf("%d",&array[i][j]);
    }
    do
    {
        t=in(n,queue[0]);
        for(i=0;queue[i]!=0;i++)
            queue[i]=queue[i+1];
        for(j=i;j<count[t][0];j++)
            queue[j]=array[t][j-i];
        count[t][1]=1;
    }while(queue[0]!=0);

    for(i=0;i<n;i++)
        if(count[i][1] == 1)
            c+=count[i][0];
}
