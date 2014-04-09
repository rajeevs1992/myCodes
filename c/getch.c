#include<stdio.h>
int main()
{
    int ch;
	system("stty raw");
    ch = getchar();
	system("stty cooked");
    if(ch == 127)
        return -1;
    else
        printf("%c",ch);
}
