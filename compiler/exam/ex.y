%{
#include<stdio.h>    
%}
%token NUM
%start S
%%
S:E{printf("%d\n",$1);};
E:E '+' E { $$ = $1 + $3; }
 |E '*' E { $$ = $1 * $3; }
 |E '-' E { $$ = $1 - $3; }
 |E '/' E { $$ = $1 / $3; }
 |F;
F:NUM | '(' E ')'{ $$ = $2;}; 
%%
int main()
{
    return yyparse();
}
int yyerror(char *s)
{
    printf("%s\n",s);
    return 0;
}
int yywrap()
{
    return 1;
}
