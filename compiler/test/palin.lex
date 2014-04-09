%{
    #include "y.tab.h"
%}
num [0-9]+

%%
{num} {yylval=(int )yytext;return N;}
\n {return NL;}
%%
