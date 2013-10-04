%{
    #include<stdio.h>
%}

%token ID
%token NUM
%token SWITCH DEF CASE BREAK CHAR AP
%start S

%%
	S : SWITCH '(' ID ')' '{'  B '}' {printf("Grammar Passed Successfully\n");exit(0);};
    B : C DEFAULT B|;
    C : CASE  CH ':' ST BR| ;
    CH : NUM | CHAR ;
    DEFAULT : DEF ':' ST BR| ;
    ST : ID '=' E ';' ST| ;
    E : E '+' T | T;
    T : T '*' F | F;
    F : ID | NUM | '(' E ')';
    BR : BREAK ';'| ;
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
