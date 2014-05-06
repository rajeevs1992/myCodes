#include<stdio.h>
int main()
{
    int n,m,t,num,temp,i,flag;
	unsigned char list[100] = {0};
    char chef[100000]={0},ass[100000]={0};
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d%d",&m,&n);
        while(n--)
        {
            scanf("%d",&num);
    		list[num/8]=list[num/8]|(1<<num%8);
        }
        for(temp=0;temp<num;temp++)
            for(i=0;i<8;i++)
                if(list[temp]&(1<<i))
                    if(flag==0)
                    {
                        printf("%d\t",temp*8+i);
                    }
                    else
                    {
                        
                    }
                        
    }
    return 0;
}
