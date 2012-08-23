#include<stdio.h>
#include<string.h>
int count=0;
void search(char *,char *,int);
int main()
{
	char str[80],sub[20];
	printf("\nEnter string ");
	gets(str);
	printf("\nEnter substring ");
	gets(sub);
	search(str,sub,0);
}
int len=strlen(sub);

void search(char *s1,char *s2,int state)
{
	if(state==len)
	{
		count++;
		state=0;
	}
	if(s1='\0')
		printf("%d",count);
	if((*s1)++==(*s2)++
		
		
