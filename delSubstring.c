#include<stdio.h>
#include<string.h>
void substring(char*,char*);
int main(int argc,char **argv)
{
	char str[100],sub[25];
	printf("\nEnter the main string ");
	gets(str);
	printf("\nEnter the string to be deleted ");
	gets(sub);
	substring(str,sub);
}

void substring(char main[],char sub[])
{
	int l1,l2,i,j,k=0,count=0,flag=-1;
	char new[100];
	int index[25];
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
			index[count++]=i;
	}
	j=0;
	for(i=0;i<l1;i++)
	{
		if(index[j]==i&&count-1>=j)
		{
			i+=l2-1;
			j++;
		}
		else
			new[k++]=main[i];
	}
	new[k]='\0';
	printf("\nString after deletion \n");
	puts(new);
		
}

Output:

rajeevs@rajeev:~/myFiles/programs$ cc delSubstring.c

rajeevs@rajeev:~/myFiles/programs$ ./a.out

Enter the main string hello ello ello

Enter the string to be deleted el 

String after deletion 
hlo lo lo


