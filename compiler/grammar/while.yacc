%{
    #include<stdio.h>
%}

%token ID
%token NUM
%start E

%%

    E : E '+' T | T;
    T : T '*' F | F;
    F : ID | NUM | '(' E ')';
%%

int main()
{
	return (yyparse());
}
int yywrap()
{
	return 0;
}

yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
}
