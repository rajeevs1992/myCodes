%{
#include "y.tab.h"
int iden=0,op=0,key=0,num=0;
%}
iden [a-zA-Z][a-zA-Z0-9\(\)]*
pre #include<[a-z]*\.h>

%%
int|float|char {yylval=yytext;return KEYWORD;}
{pre} {return PRE;}
\{ {return '{';}
\} {return '}';}
{iden} {yylval=yytext;return VAR;}
; {return ';';}
%%
