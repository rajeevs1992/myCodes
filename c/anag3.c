#include <stdio.h>
#include<string.h>
char s[100000][20];int v,p=0;

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  

void permute(char *a, int i, int n)
{
   int j,k;
   if (i == n)
    {   
        for(k=0;k<p;k++)
	{
		if(strcmp(s[k],a)==0)//avoid repeatation
		goto l;
	}
	strcpy(s[p],a);
	p++;
     }
l: 
   if(i!=n)
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}

 
int main()
{
   char a[100],t[20];int len,i,j;
   printf("Enter the word:\t");
   gets(a);
   len=strlen(a);v=len;	
   permute(a, 0, len-1);
   for(i=1;i<p;i++)//sorting
    {
    for(j=1;j<p;j++)
        {
        if(strcmp(s[j-1],s[j])>0)
            {
            strcpy(t,s[j-1]);
            strcpy(s[j-1],s[j]);
            strcpy(s[j],t);
            }
        }
    }
	for(i=0;i<p;i++)//printing
	puts(s[i]);
    return 0;
}


