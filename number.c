//This program takes input mode from user and then converts it to all other number systems.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void binary(int no);
int decimal(int no,int mode,char *);
void hex(int no);
void oct(int no);
int hexKey(char digit,int power);
void main()
{
	system("clear");
	int ch,n,t;
	char no[10];
	fail:
	do
	{
		ch=n=0;
		printf("\n\n\nEnter input mode\n1.Binary\n2.Decimal ");
		printf("\n3.Heaxadecimal\n4.Octal\n5.EXIT ");
		scanf("%d",&ch);
		system("clear");
		if(ch<5)
		{
		printf("\nEnter the number ");
		gets(no);
		gets(no);
		}
		//Validate input
		if(ch!=3&&ch<5)
			if(atoi(no)==0)
			{
				printf("\nValidate fail!");
				goto fail;
			}
			else
				n=atoi(no);
		t=n;
		switch(ch)
		{
			case 1:
				n=decimal(n,1,'\0');
				if(n==-1)
				{
					system("clear");				
					printf("\nValidate fail!");
					goto fail;
				}
				printf("\nBinary %d",t);
				hex(n);
				oct(n);
				break;
			case 2:
				printf("\nDecimal %d ",n);
				binary(n);
				hex(n);
				oct(n);
				break;
			case 3:
				n=decimal	(0,3,no);
				if(n==-1)
					{
						system("clear");
						printf("\nValidate fail!");
						goto fail;
					}
				printf("\nHexadecimal %s ",no);
				binary(n);
				oct(n);
				break;
			case 4:
				n=decimal(n,4,'\0');
				if(n==-1)
					{
						system("clear");
						printf("\nValidate fail!");
						goto fail;
					}
				printf("\nOctal %d ",t);
				binary(n);
				hex(n);
				break;
		}
	}while(ch<5);
}

//Function to convert any number format to decimal
int decimal(int no,int mode,char noh[10])
{
	int sum=0,temp,i;
	switch(mode)
	{
		case 1:
			i=0;
			while(no)
			{
				temp=no%10;
				if(temp>1)
					return -1;
				no=no/10;
				if(temp==1)
					sum+=pow(2,i);
				i++;
			}
			printf("\nDecimal %d ",sum);
			return sum;
		case 3:
			i=0;
			int t;
			for(i=strlen(noh)-1;i>=0;i--)
			{
				t=hexKey(noh[i],strlen(noh)-i-1);
				if(t==-1)
					return t;
				sum+=t;
			}
			printf("\nDecimal %d ",sum);
			return sum;
		case 4:
			i=0;
			while(no)
			{
				temp=no%10;
				if(temp>7)
					return -1;
				no=no/10;
				sum+=temp*pow(8,i);
				i++;
			}
			printf("\nDecimal %d ",sum);
			return sum;
	}
}
//Function to generate decimal equivalent of a hex digit
int hexKey(char digit,int power)
{
	char digitList[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},i;
	int flag;
	for(i=0;i<16;i++)
		if(digitList[i]==digit)
			{flag=1;break;}
	if(flag!=1)
		return -1;
	for(i=0;i<16;i++)
		if(digitList[i]==digit)
			return i*pow(16,power);		
}				
//Function that converts decimal number to binary.
void binary(int no)
{
	int temp[50],i=0,j;
	while(no)
	{
		temp[i]=no%2;
		i++;
		no=no/2;
	}
	printf("\nBinary ");
	for(j=i-1;j>=0;j--)
		printf("%d",temp[j]);
}
//Function to convert decimal to hex
void hex(int no)
{
	int hexa[50],i=0,j,k;
	char digitList[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	while(no)
	{
		hexa[i]=no%16;
		i++;
		no=no/16;
	}
	printf("\nHexadecimal ");
	for(j=i-1;j>=0;j--)
		for(k=0;k<16;k++)	
			if(hexa[j]==k)
			{
				printf("%c",digitList[k]);
				break;
			}
}
//Function to convert decimal to octal
void oct(int no)
{
	int i=0,j,temp[25];
	while(no)
	{
		temp[i]=no%8;
		no=no/8;
		i++;
	}
	printf("\nOctal ");
	for(j=i-1;j>=0;j--)
		printf("%d",temp[j]);
}

			
				
				
	
