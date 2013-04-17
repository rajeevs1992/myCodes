#include<pthread.h>
#include<malloc.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *temp;
struct node * insert(int in,struct node *root);
void display(struct node *);
void LCA(int n1,int n2,struct node *root);
int search(struct node *root,int key);
void *start(void *arg);
int af=0,bf=0;
int in,n1,n2;
int main()
{
    struct node *root=NULL;
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
    LCA(n1,n2,root);
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
int search(struct node *root,int key)
{  
    if(root==NULL)
        return 0;
    else if (root->data==key) 
        return 1;
    else if(root->data>key)
        return search(root->left,key);
    else
        return search(root->right,key);
}
void *start(void *arg)
{
    int m=(int)arg;
    if(m==0)
    {
        if(search(temp->left,n1))
            af=1;
    }
    else
    {
        if(search(temp->right,n2))
            bf=1;
    }
}
void LCA(int n1,int n2,struct node *root)
{
    pthread_t t[2];
    while(1)
    {
        temp=root;
        pthread_create(&t[0],NULL,start,(void *)1);
        pthread_create(&t[1],NULL,start,(void *)0);
        pthread_join(t[0],NULL);
        pthread_join(t[1],NULL);
        if(af && bf)
        {
            printf("The LCA is %d \n",root->data);
            break;
        }
        else if(af)
            root=root->left;
        else if(bf)
            root=root->right;
    }
}

Output:

Enter the node 500
Enter the node 250
Enter the node 125
Enter the node 750
Enter the node 625
Enter the node 0
125 250 500 625 750 
Find LCA of 125 625
The LCA is 500
