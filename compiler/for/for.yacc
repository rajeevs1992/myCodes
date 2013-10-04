%{
    #include<stdio.h>
%}

%token ID
%token NUM
%token FOR COND
%start S

%%
	S : FOR'('POST';'EXP';'POST')''{'ST'}'{printf("Grammar Passed Successfully\n");exit(0);} | FOR'('POST';'EXP';'POST')'';' {printf("Grammar Passed Successfully\n");exit(0);};
	EXP : ID COND ID | ID COND NUM | EXP COND EXP |;
    POST : ID '=' E | ID '=' E ',' ID '=' E | ;
    ST : ID '=' E ';' ST| ;
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
