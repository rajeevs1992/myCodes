#include<pthread.h>
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
void *start();
int in,n1,n2;
void LCA();
int main()
{
    int t;
    while(1)
    {
        printf("\nEnter the node ");
        scanf("%d",&in);
        if(in == 0)
            break;
        root=insert(in,root);
    }
    display(root);
    printf("\nFind LCA of ");
    scanf("%d",&n1);
    scanf("%d",&n2);
    if(n1>n2)
    {
        t=n2;
        n2=n1;
        n1=t;
    }
    LCA();

}
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d\t",root->data);
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
    pthread_t t;
    pthread_create(&t,NULL,start,NULL);
    pthread_join(t,NULL);
}
void *start()
{
    struct node *temp=root;
    while(1)
    {
        if(n1<temp->data<n2)
        {
            printf("\nLCA is %d ",temp->data);
            exit(0);
        }
        else if(n1<n2<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
}
