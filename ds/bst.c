#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
int deletemin(node *root);
node *delete(node *root,int element,node *prev);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
main()
{
	int ch;
	node *root=NULL,*temp,*runner;
	while(1)	
	{
		printf("\nEnter choice \n1.Insert\t2.Delete\t3.Preorder\t4.Inorder\t5.Postorder\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the new node ");
				temp=(node *)malloc(sizeof(node));
				scanf("%d",&temp->data);
				if(root==NULL)
					root=temp;
				else
				{
					runner=root;
					while(1)
					{
						if(runner->data>temp->data)
						{
							if(runner->right==NULL)
							{
								runner->right=temp;
								break;
							}
							else
								runner=runner->right;
						}
						else
						{
							if(runner->left==NULL)
							{
								runner->left=temp;
								break;
							}
							else
								runner=runner->left;
						}
					}
				}
				break;
			case 2:
				printf("\nEnter element ");
				scanf("%d",&ch);
				root=delete(root,ch,NULL);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				inorder(root);
				break;

		}
	}
}
node *delete(node *root,int element,node *prev)
{
	if(root !=NULL)
	{
		if(element < root->data)
			delete(root->left,element,root);
		else if(element > root->data)
			delete(root->right,element,root);
		else if(root->left==NULL && root->right==NULL)
		{
			prev=NULL;
			root=NULL;
		}
		else if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
		else
			root->data=deletemin(root->right);
	}
	root=NULL;
}

int deletemin(node *root)
{
	if(root->left==NULL)
	{
		root=root->right;
		return root->data;
	}
	else
		return deletemin(root->left);
}

void preorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void postorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
