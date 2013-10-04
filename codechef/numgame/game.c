#include<stdio.h>
int ifprime(int n)
{
    if(n<2)
        return 0;
    int t=n/2,i;
    for(i=2;i<t;i++)
        if(n%i == 0)
            return 0;
    return 1;
}
int main()
{
    int board[1000]={0},player=1,i,j,s1=0,s2=0,k,l,t;
    scanf("%d",&board[0]);
    i=1;
    while(1)
    {
        for(i=0;i<1000;i++)
        {
            if(player==0)
                player=1;
            else
                player=0;

            if(board[i]==0)
                continue;
            else if(board[i] == 1 || ifprime(board[i]))
            {
                if(player==1)
                    s2++;
                else
                    s1++;
                board[i]=board[i]-1;
                break;
            }
            else
            {
                for(k=2;k<board[i]/2;k++)
                    if(board[i]%k==0)
                    {
                        t=board[i]/k;
                        board[i]=t;
                        for(l=0;l<1000;l++)
                            if(board[l]==0)
                            {
                                board[l]=k;
                                break;
                            }
                        break;
                    }
               break;
            }
        }
        k=1;
        for(l=0;l<1000;l++)
        {
            if(board[l]!=0)
            {
                k=0;
                break;
            }
        }
        if(k==1)
            break;
    }
    if(s1>s2)
        printf("%d %d\n",s1,s2);
    else
        printf("%d %d\n",s2,s1);
}
