#include<stdio.h>
#include<ctype.h>
int hole(char a)
{
    switch(a)
    {   
        case 'A':
        case 'D':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':return 1;break;
        case 'B':return 2;break;
        default : return 0;
    }
}
int main()
{
    int limit,i,sum;
    char ch;
    scanf("%d",&limit);
    ch = getchar();
    for(i=0;i<limit;i++)
    {
        sum = 0;
        do
        {
            ch = getchar();
            if(ch == '\n')
                break;
            else
                sum += hole(ch);
        }while(1);
        printf("%d\n",sum);
    }
    return 0;

}
