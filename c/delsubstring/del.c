#include<stdio.h>
#include<string.h>
void substring(char*,char*);
int main(int argc,char **argv)
{
	char str[1000],sub[25];
    int n,i;
    scanf("%d",&n);
    gets(str);
    for(i=0;i<n;i++)
    {
    	gets(str);
	    gets(sub);
    	substring(str,sub);
    }
    return 0;
}

void substring(char main[],char sub[])
{
	int l1,l2,i,j,k=0,count=0,flag=-1;
	char new[100];
	int index[25];
	l1=strlen(main);
	l2=strlen(sub);
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
			if(main[i+j]==sub[j])
				flag=1;
			else
			{
				flag=0;
				break;
			}
		if(flag==1)
			index[count++]=i;
	}
	j=0;
	for(i=0;i<l1;i++)
	{
		if(index[j]==i&&count-1>=j)
		{
			i+=l2-1;
			j++;
		}
		else
			new[k++]=main[i];
	}
	new[k]='\0';
	puts(new);
		
}

