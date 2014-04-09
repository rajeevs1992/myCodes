%{
    #include<stdio.h>
%}
comment \/\*(.|[\r\n])*\*\/ 
single \/\/.*
%%
{comment} {printf("");}
{single} {printf("");}


%%

int main(int argc,char *argv[])
{
    FILE *r=fopen(argv[1],"r");
    FILE *w=fopen(argv[2],"w");
    yyout=w;
    yyin=r;
    return yylex();
}

int yywrap()
{
    return 1;
}
int yyerror(char *s)
{
    printf("%s\n",s);
}
