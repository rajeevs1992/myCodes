#include<stdio.h>
#include<string.h>
char stack[100],top=-1;
void push(char);
char pop();
void main()
{
	char postfix[100],infix[100],temp[100],i=0,j=0;
	printf("\nEnter the expression,Paranthesized ");
	scanf("%s",infix);
	while(infix[i]!='\0')
	{
		if(infix[i]!=')')
			push(infix[i]);
		else
		{
			postfix[j+1]=pop();
			postfix[j+2]=pop();
			postfix[j]=pop();
			j+=3;
		}
		i++;
	}
	postfix[j]='\0';
	int l=strlen(postfix);
	j=0;
	for(i=0;i<l;i++)
		if(postfix[i]!='(')
			temp[j++]=postfix[i];
	temp[j]='\0';
	strcpy(postfix,temp);
	puts(postfix);
}

void push(char ch)
{
	stack[++top]=ch;
}

char pop()
{
	return stack[top--];
}


