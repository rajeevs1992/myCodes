#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createTree();
void preOrder(struct node *root);

main()
{
	struct node *root=createTree();
	preOrder(root);
}

struct node *createTree()
{
	struct node *root,*temp,*byRunner;
	char ch;
	root=(struct node *)malloc(sizeof(root));
	printf("\nEnter root data ");
	scanf("%d",&root->data);
	root->left=root->right=NULL;
	temp=root;
	printf("\nCreate Binary tree ");
	printf("\nWant to enter more?y/n ");
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch=='y')
	{
		byRunner=(struct node *)malloc(sizeof(byRunner));
		printf("\nEnter data ");
		scanf("%d",&byRunner->data);
		byRunner->left=byRunner->right=NULL;
		do
		{
		if(temp->data <= byRunner->data) 
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else
			{
				temp->left=byRunner;
				temp=root;
			}
		}
		else
		{
			if(temp->right != NULL)
			{
				temp=temp->right;
			}
			else
			{
				temp->right=byRunner;
				temp=root;
			}
		}
		}while(temp!=root);

				printf("\nWant to enter more?y/n ");
				scanf("%c",&ch);
				scanf("%c",&ch);
	}
	return temp;
}

void preOrder(struct node *head)
{
	if(head!=NULL)
	{
	preOrder(head->left);
	printf("%d\t",head->data);
	preOrder(head->right);
	}
}
