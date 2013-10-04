#include<stdio.h>
char key[6][5]={"abcde","fghij","klmno","pqrst","uvwxy","z"};
void getpos(int pos[2],char c)
{
    int i,j;
    for(i=0;i<6;i++)
        for(j=0;j<5;j++)
            if(key[i][j] == c)
            {
                pos[0]=i;
                pos[1]=j;
            }
}
int main()
{
    int l,i,j,pos[2],cur[2];
    char str[100];
    scanf("%s",str);
    getpos(cur,str[i]);
    for(i=1;str[i]!=0;i++)
    {
        printf("!.");
        getpos(pos,str[i]);
        while(cur[0] < pos[0])
        {
            cur[0]++;
            printf("01100100.");
        }
        while(cur[0]>pos[0])
        {
            cur[0]--;
            printf("01110101.");
        }
        while(cur[1] < pos[1])
        {
            cur[1]++;
            printf("01110010.");
        }
        while(cur[1]>pos[1])
        {
            cur[1]--;
            printf("01101100.");
        }
    }
    printf("!\n");
    return 0;
}
