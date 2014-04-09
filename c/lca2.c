#include<malloc.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node * insert(int in,struct node *root);
void display(struct node *);
int in,n1,n2;
void LCA();
int main()
{
    int t,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&in);
        root=insert(in,root);
    }
    display(root);
    scanf("%d",&n1);
    scanf("%d",&n2);
    if(n1>n2)
    {
        t=n2;
        n2=n1;
        n1=t;
    }
    LCA();
    return 0;

}
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        display(root->right);
    }
}
struct node * insert(int in,struct node *root)
{
    if(root==NULL)
    {
        root=(struct node *)malloc(sizeof(root));
        root->data=in;
        root->left=NULL;
        root->right=NULL;
    }
    else if(root->data>in)
        root->left=insert(in,root->left);
    else
        root->right=insert(in,root->right);
    return root;
}
void LCA()
{
    struct node *temp=root;
    while(1)
    {
        if(n1<temp->data<n2)
        {
            printf("%d\n",temp->data);
            break;
        }
        else if(n1<n2<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
}
