%{
    #include<stdio.h>
    #include<string.h>
%}
%token N NL
%start E
%%
    E: S NL {printf("Success\n");return 0;};
    S:'0' S '1' |;
%%
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
    
