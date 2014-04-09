%{
    #include<stdio.h>
    #include<string.h>
%}
%token N NL
%start E
%%
    E:S NL {printf("Success\n");return 0;};
    S: '0' S '0'| '1' S '1'|'0'|'1'|;
%%
int yywrap()
{
    return 1;
}
int main()
{
 //   extern int yydebug;
   // yydebug = 1;
    return yyparse();
}
yyerror(char *s)
{
    printf("%s\n",s);
}
    
