#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct list
{
    int index;
    int l;
    char word[1000];
    struct list *next;
};
struct node
{
    int index;
    struct node *next;
};
int main()
{
    int n,i,k,l,c,t;
    char beg,end;
    struct list *front,*rear,*temp;
    struct node *r,*new,*f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i].word);
            str[i].index = i;
            l=strlen(str[i].word);
            str[i].l = l;
        }
        beg=str[0].word[0];
        end=str[0].word[str[0].l-1];
        f =(struct node *)malloc(sizeof(struct node));
        f->index=0;
        f->next=NULL;
        r=f;
        str[0].index=-1;
        while(1)
        {
            l=1;
            c=0;
            for(i=1;i<n;i++)
            {
                if(str[i].index!=-1)
                {
                    if(str[i].word[0] == end)
                    {
                        new =(struct node *)malloc(sizeof(struct node));
                        new->index=i;
                        new->next=NULL;
                        r->next=new;
                        r=new;
                        str[i].index =-1;
                        l=0;
                    }
                    else if(str[i].word[str[i].l -1] == beg)
                    {
                        new =(struct node *)malloc(sizeof(struct node));
                        new->index=i;
                        new->next=f;
                        f=new;
                        str[i].index =-1;
                        l=0;
                    }
                }
                else
                    c++;
            }
            if(l==1 && i==n)
            {
                printf("The door cannot be opened.\n");
                break;
            }
            if(c==n)
            {
                printf("Ordering is possible.\n");
                break;
            }
        }
    }
    return 0;
}
