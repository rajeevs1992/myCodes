#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int k,n,i,l,count=0,num;
    char tweet[1000000] = {0};
    char command[15];
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        fgets(command,12,stdin);
        printf("%s",command);
        if(command[5] == 'A')
        {
            count = 0;
            memset(tweet,0,1000000);
        }
        else
        {
            num = atoi(command + 5);
            printf("%d",num);
            if(tweet[num] == 1)
            {
                tweet[num] = 0;
                count--;
            }
            else
            {
                tweet[num] = 1;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
