#include<stdio.h>
#include<stdlib.h>
int queue[100],front=0,rear=0,max;
void PUSH();
void POP();
void display();
void main()
{
	int ch;
	char temp[15];
	printf("\nEnter the limit ");
	scanf("%d",&max);
	FILE *fp=fopen("a","a");
	FILE *fi=fopen("/dev/stdin","r");
	if(fork()==0)
	{
		while(1)
		{
			fscanf(fi,"%s",temp);
			fprintf(fp ,"%s",temp);
			fclose(fp);
			fclose(fi);
		}
	}
	while(1)
	{
		printf("\nEnter choice\n1.Push\n2.Pop\n3.Display\n4.Exit ");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
				PUSH();
				break;
			case 2:
				POP();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}
void PUSH()
{
	if(rear==max)
		printf("\nQueue full!!!!!\n");
	else
	{
		printf("\nEnter the element ");
		scanf("%d",&queue[rear++]);
	}
	return;
}
void POP()
{
	if(front==rear)
		printf("\nQueue empty!!!!!!\n");
	else
		printf("\nPopped %d\n",queue[front++]);
	return;
}
void display()
{
	int i;
	if(front==rear)
		printf("\nQueue empty!!!!!!\n");
	else
		for(i=front;i<rear;printf("%d\t",queue[i++]));
}


