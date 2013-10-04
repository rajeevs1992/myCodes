%{#include<stdio.h>
int i;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
invalid_id [0-9][a-zA-Z0-9]*
number [0-9]*

%%

if|else|main|int|float|char|void {
printf("Keyword");
}
{invalid_id} {
printf("Invalid Id");
}

{identifier} {
printf("Identifier");
}
{number} {
printf("Number");
}
%%

main()
{
yyin=stdin;
yylex();
}

int yywrap()
{
return 1;
}
