%{
    #include<stdio.h>
%}

%token ID
%token NUM OP
%start E

%%
    E: E '+' E {printf("+");}
    |E '-' E {printf("-");}
    |E '*' E {printf("*");}
    |E '/' E {printf("/");}
    |F;
    F:NUM {printf(" %s ",$1);}|'('E')';
%%

int main()
{
	return (yyparse());
}
int yywrap()
{
	return 1;
}

yyerror(char *s)
{
	fprintf(stderr,"%s",s);
}
