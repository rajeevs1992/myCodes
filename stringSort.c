#include<stdio.h>
#include<string.h>
void sort(char str[][25],int no);
int main()
{
	char string[100][25];
	int number,i;
	printf("\nEnter the number of strings ");
	scanf("%d",&number);
	gets(string[0]);
	for(i=0;i<number;i++)
	{
		printf("\nEnter string number %d ",i+1);
		gets(string[i]);
	}
	sort(string,number);
}
//Function that performs Lexiographical sorting using bubble sort algorithm
void sort(char str[][25],int no)
{
	int i,j;
	char temp[25];
	for(i=0;i<no;i++)
		for(j=0;j<no-1;j++)
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
	for(i=0;i<no;i++)
		puts(str[i]);
}

Output:
rajeevs@rajeev:~/myFiles/programs$ cc stringSort.c

rajeevs@rajeev:~/myFiles/programs$ ./a.out

Enter the number of strings 5

Enter string number 1 aaa

Enter string number 2 bbb

Enter string number 3 def

Enter string number 4 hew

Enter string number 5 uyt
aaa
bbb
def
hew
uyt

