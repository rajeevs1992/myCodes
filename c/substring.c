#include<stdio.h>
#include<string.h> //for strlen()
int substring(char*,char*);
int main()
{
	char mainString[50],subString[25];
	printf("\nEnter the main string ");
	gets(mainString);
	printf("\nEnter string to be searched for ");
	gets(subString);
	int ret=substring(mainString,subString);
	printf("\nThe string occours %d times ",ret);
}
//Function to search for substring
int substring(char main[],char sub[])
{
	int l1,l2,i,j,count=0,flag=-1;
	l1=strlen(main);
	l2=strlen(sub);
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
			if(main[i+j]==sub[j])
				flag=1;
			else
			{
				flag=0;
				break;
			}
		if(flag==1)
			count++;
	}
	return count;
}

Output:
rajeevs@rajeev:~/myFiles/programs$ cc substring.c

rajeevs@rajeev:~/myFiles/programs$ ./a.out

Enter the main string hello world

Enter string to be searched for ello

The string occours 1 times 
