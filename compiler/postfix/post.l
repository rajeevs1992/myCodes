%{
#include"y.tab.h"
%}

iden [a-zA-Z][a-zA-Z0-9]*
number [0-9]*

%%

{iden} {yylval=yytext;return ID;}
{number} {yylval=yytext;return NUM;}
\* {yylval=yytext;return '*';}
\- {yylval=yytext;return '-';}
\+ {yylval=yytext;return '+';}
\/ {yylval=yytext;return '/';}
\( {return '('; }
\) {return ')'; }


%%
