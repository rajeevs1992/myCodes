%{
#include<ctype.h>
#include "y.tab.h"
%}
number [0-9]*
%%
{number} {yylval=atoi(yytext);return NUM;}
\( {yylval=(int)yytext;return '(';}
\) {yylval=(int)yytext;return ')';}
\+ {yylval=(int)yytext;return '+';}
\- {yylval=(int)yytext;return '-';}
\* {yylval=(int)yytext;return '*';}
\/ {yylval=(int)yytext;return '/';}
%%
