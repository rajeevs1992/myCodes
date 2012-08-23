#include<stdio.h>
#include<stdlib.h>
#define SIZE(n) (n+8-(n%8))/8
#define PRESENT 1
#define ABSENT 0
#define POS(n) n/8
struct number
{
	unsigned char num0:1;
	unsigned char num1:1;
	unsigned char num2:1;
	unsigned char num3:1;
	unsigned char num4:1;
	unsigned char num5:1;
	unsigned char num6:1;
	unsigned char num7:1;
};
void set(int num,struct number list[]);
void display(int limit,struct number list[]);
void SetToZero(int limit,struct number list[]);
main()
{
	int num=0,upper;
	printf("\nEnter largest number in list ");
	scanf("%d",&upper);
	upper+=1;
	struct number list[SIZE(upper)];
	printf("%d",sizeof list);
	SetToZero(SIZE(upper),list);
	printf("Enter the list  ");
	scanf("%d",&num);
	while(num<upper)
	{
		set(num,list);
		scanf("%d",&num);
	}
	display(SIZE(upper),list);
}
void SetToZero(int limit,struct number list[])
{
//Initialized the whole list with 0
	int i;
	for(i=0;i<limit;i++)
	{
		list[i].num0=ABSENT;
		list[i].num1=ABSENT;
		list[i].num2=ABSENT;
		list[i].num3=ABSENT;
		list[i].num4=ABSENT;
		list[i].num5=ABSENT;
		list[i].num6=ABSENT;
		list[i].num7=ABSENT;
	}
}
void set(int num,struct number list[])
{
//Function sets the recieved number on to the list
	switch(num%8)
	{
		case 0:
			list[POS(num)].num0=PRESENT;
			break;
		case 1:
			list[POS(num)].num1=PRESENT;
			break;
		case 2:
			list[POS(num)].num2=PRESENT;
			break;
		case 3:
			list[POS(num)].num3=PRESENT;
			break;
		case 4:
			list[POS(num)].num4=PRESENT;
			break;
		case 5:
			list[POS(num)].num5=PRESENT;
			break;
		case 6:
			list[POS(num)].num6=PRESENT;
			break;
		case 7:
			list[POS(num)].num7=PRESENT;
			break;
	}
}
void display(int limit,struct number list[])
{
//Displays the list,automatically sorted
	int i=0;
	for(i=0;i<limit;i++)
	{
		if(list[i].num0)
			printf("%d\t",i*8);
		if(list[i].num1)
			printf("%d\t",i*8+1);
		if(list[i].num2)
			printf("%d\t",i*8+2);
		if(list[i].num3)
			printf("%d\t",i*8+3);
		if(list[i].num4)
			printf("%d\t",i*8+4);
		if(list[i].num5)
			printf("%d\t",i*8+5);
		if(list[i].num6)
			printf("%d\t",i*8+6);
		if(list[i].num7)
			printf("%d\t",i*8+7);
	}
	printf("\n");
}
