%{
#include"y.tab.h"
#include<ctype.h>
%}

iden [a-zA-Z][a-zA-Z0-9]*
number [0-9]*

%%

{iden} {yylval=yytext;return ID;}
{number} {yylval=atoi(yytext);return NUM;}
\* {yylval=yytext;return '*';}
\- {yylval=yytext;return '-';}
\+ {yylval=yytext;return '+';}
\/ {yylval=yytext;return '/';}
\( {return '('; }
\) {return ')'; }


%%
