%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    FILE *fp;
    int calcsize(char *s)
    {
        if(strncmp("int",s,3)==0)
            return sizeof(int);
        if(strncmp("char",s,4)==0)
            return 1;
        if(strncmp("float",s,5)==0)
            return 8;
    }
    char * chop(char *s)
    {
        int i;
        for(i=0;s[i]!=' ';i++);
        s[i]=0;
        return s;
    }
%}
%start E
%token KEYWORD VAR ELSE PRE
%%
E:P S '{' S '}' E|;
P:PRE|;
S:KEYWORD VAR {fprintf(fp,"<tr><td>%s</td><td>%s</td><td>%d</td></tr>",chop($1),$2,calcsize($1));
               printf("%s---%s---%d",$1,$2,calcsize($1));} COL S 
    |
    ;
COL:';'|;
%%

int main()
{
    fp=fopen("symtab.html","w");
    fprintf(fp,"<html><table border=1><tr><th>Type</th><th>Symbol</th><th>Size</th></tr>");
    printf("Type---Symbol---Size");
    int a=yyparse();
    fclose(fp);
    return a;
}
yyerror(s)
char *s;
{
    fprintf(stderr,"%s\n",s);
}
int yywrap()
{
	return 1;
}	


