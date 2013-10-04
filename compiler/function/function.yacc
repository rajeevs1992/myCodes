%{
    #include<stdio.h>
%}

%token ID
%token KEYWORD
%start S

%%
	S : DEC '(' DEC ')' ';'{printf("String Accepted\n");exit(0);} ;
    DEC : KEYWORD  PTR VAR COMMA DEC | ;
    VAR : ID | ;
    PTR : '*' | ;
    COMMA : ',' | ;
%%

main()
{
	return (yyparse());
}
yywrap()
{
	return 0;
}

yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
}
