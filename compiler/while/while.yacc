%{
    #include<stdio.h>
%}

%token ID
%token NUM
%token WHILE COND DO
%start S

%%
	S : WHILE '(' EXP ')' ST {printf("Grammar Passed Successfully\n");exit(0);}
      | WHILE '(' EXP ')' '{' ST {printf("here");}'}' {printf("Grammar Passed Successfully\n");exit(0);} 
      | D {printf("Grammar Passed Successfully\n");exit(0);} ;

    D : DO '{' ST '}' WHILE '(' EXP ')' ';';

	EXP : ID COND ID;
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
