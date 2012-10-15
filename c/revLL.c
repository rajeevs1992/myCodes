#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

char getch()
{
	system("stty raw");
	char ch=getchar();
	system("stty cooked ");
	return ch;
}

struct node *getlist()
{
	//Reads the polynomial and returns the first node
	struct node *first,*temp,*byRunner;
	first=(struct node *)malloc(sizeof first);
	printf("\nEnter node ");
	scanf("%d",&first->data);
	first->next=NULL;
	temp=first;
	printf("\nEnter more ? ");
	getch();
	while(getch()=='y')
	{
		byRunner=(struct node *)malloc(sizeof byRunner);
		printf("\nEnter node ");
		scanf("%d",&byRunner->data);
		byRunner->next=NULL;
		temp->next=byRunner;
		temp=byRunner;
		printf("\nEnter more ? ");
		getch();
	}
	return first;
}

void display(struct node * first)
{
	struct node *temp=first;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}

void reverse(struct node * first)
{
	struct node *p1,*p2,*p3;
	p1=first;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	while(p3!=NULL)
	{
		p2->next=p1;
		p1=p2;
		p2=p1->next;
		p3=p2->next;
	}
	display(p2);
}

int main()
{
	struct node *list=getlist();
	reverse(list);
	return 0;
}
	
	
	

