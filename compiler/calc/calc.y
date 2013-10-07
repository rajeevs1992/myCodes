%{
    #include<stdio.h>
%}

%token ID
%token NUM OP
%start S

%%
    S:E{printf("%d\n",$1);};
    E: E '+' E {$$ = $1 + $3;}
    |E '-' E {$$ = $1 - $3;}
    |E '*' E {$$ = $1 * $3;}
    |E '/' E {$$ = $1 / $3;}
    |F;
    F:NUM |'(' E ')'{$$=$2;};;
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
	fprintf(stderr,"%s\n",s);
}
