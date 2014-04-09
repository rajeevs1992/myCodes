#include<stdio.h>
#include<string.h>
int main()
{
    int l,i,f=0;
    char str[50];
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l/2;i++)
        if(str[l-i-1] != str[i])
        {
            f=1;
            break;
        }
    if(f==0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
