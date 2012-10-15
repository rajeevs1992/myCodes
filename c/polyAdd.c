#include<stdio.h>
#include<stdlib.h>//For malloc
struct node
{
	int exp;
	int coefft;
	struct node *next;
};

char getch()
{
	//For single touch input of choices
	char ch;
	system("stty raw");
	ch=getchar();
	system("stty cooked");
	return ch;
}

struct node *getPoly()
{
	//Reads the polynomial and returns the first node
	struct node *first,*temp,*byRunner;
	first=(struct node *)malloc(sizeof first);
	printf("\nEnter coefft ");
	scanf("%d",&first->coefft);
	printf("\nEnter exponent ");
	scanf("%d",&first->exp);
	first->next=NULL;
	temp=first;
	printf("\nEnter more ? ");
	getch();
	while(getch()=='y')
	{
		byRunner=(struct node *)malloc(sizeof byRunner);
		printf("\nEnter coefft ");
		scanf("%d",&byRunner->coefft);
		printf("\nEnter exponent ");
		scanf("%d",&byRunner->exp);
		byRunner->next=NULL;
		temp->next=byRunner;
		temp=byRunner;
		printf("\nEnter more ? ");
		getch();
	}
	return first;
}

struct node *getMin(struct node *n)
{
	//Selects the minimal exponent that comes after the node n
	struct node *min=n;
	while(n!=NULL)
	{
		if(n->exp>min->exp)
			min=n;
		n=n->next;
	}
	return min;
}



struct node *sort(struct node *first)
{
	//Selection sort ,implemented on the linklist
	struct node *temp=first,*min;
	int exp,coefft;	
	while(temp!=NULL)
	{
		min=getMin(temp);
		/*----------------------------------------------
		Swapping min and the current node ie temp
		Swapping procedure is similar to the normal swap other than that 
		here there are two items to be swapped instead of one.Here the exp 
		and coefft act as temporary variables
		------------------------------------------------*/
		exp=temp->exp;
		coefft=temp->coefft;
		//---------------------temp=a
		temp->exp=min->exp;
		temp->coefft=min->coefft;
		//----------------------a=b
		min->exp=exp;
		min->coefft=coefft;
		//---------------------b=temp
		temp=temp->next;
	}
	return first;
}

void display(struct node *first)
{
	//Displays linklist as polynomial starting from first till NULL
	struct node *temp=first;
	while(temp!=NULL)
	{
		printf("(%dx^%d)+",temp->coefft,temp->exp);
		temp=temp->next;
	}
}

struct node *merge(struct node *one,struct node *two)
{
	//Merge,rather connect the two recieved linklists one and two
	struct node *temp=one;
	while(temp->next!=NULL)
		temp=temp->next;
	//Now temp is the last node of first list,whose address pasr is NULL
	temp->next=two;
	//Joined!!!
	return one;
}

struct node *add(struct node *first)
{
	//The node first is to be sorted for this algo to work
	struct node *temp=first;
	while(temp->next!=NULL)
	{
	//Compare adjacent terms of the sorted linklist and add if exp's equal
		if(temp->exp==temp->next->exp)
		{
			temp->coefft+=temp->next->coefft;
			temp->next=temp->next->next;
			//Delete the temp->next node after addition
		}
		if(temp->next!=NULL)
			temp=temp->next;
	}
	return first;
}


int main()
{
	struct node *one,*two,*temp;
	printf("\nEnter polynomial 1 ");
	one=sort(getPoly());
	temp=one;
	while(temp!=NULL)
	{
/*	This procedure is to ensure that there remains no terms in the 
	polynomial with same exponent,ie exp becomes like a primary key
	For eg (x^2)+(3x^2)+(2x^1) becomes (4x^2)+(2x^1)
	This may be avoided if you are sure that such a situation wont occour*/
		one=add(one);
		temp=temp->next;
	}
	system("clear");
	printf("\nEnter polynomial 2 ");
	two=sort(getPoly());
	temp=two;
	while(temp!=NULL)
	{
		two=add(two);
		temp=temp->next;
	}
	system("clear");
	one=merge(one,two);
	one=sort(one);
	one=add(one);
	system("clear");
	display(one);
}
