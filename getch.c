#include<stdio.h>
int main()
{
	system("stty raw");
	printf("%c",getchar());
	system("stty cooked");
	return 0;
}
