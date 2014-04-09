%{
    #include<stdio.h>
    #include<string.h>
%}
%token N NL
%start S
%%
    S:N {check($1);} NL;
%%
int check(char *s)
{
    int l=strlen(s);
    int flag=0,i,j;
    for(i=0;i<=l/2;i++)
        if(s[i]!=s[l-i-1])
        {
            flag=1;
            break;
        }
    if(flag==0)
        printf("Palindrome\n",s);
    else
        printf("Not Palindrome\n",s);
}
int yywrap()
{
    return 1;
}
int main()
{
    return yyparse();
}
yyerror(char *s)
{
    printf("%s\n",s);
}
    
