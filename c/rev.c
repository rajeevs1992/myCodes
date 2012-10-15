#include<stdio.h>
#include<string.h>
main()
{
	char string[10],i,*fp=fopen("file","r");
	while(fscanf(fp,"%s",string)!=EOF && printf(" "))
		for(i=strlen(string);i>=0;printf("%c",string[i--]));
}
